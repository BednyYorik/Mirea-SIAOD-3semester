#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

const int alfaLength = 256;

//Функция для вычисления таблицы сдвигов плохих символов.
int* preBmBc(string obrath) {
    int  table[alfaLength];
    int m = obrath.length();
    // Заполняем значением по умолчанию, равным длине шаблона
    for (int i = 0; i < alfaLength; i++)
    {
        table[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        table[obrath[i]] = m - 1 - i;
    }
    return table;
}

//Функция, проверяющая, что подстрока obrath[p…m−1] является префиксом шаблона obrat
bool isPrefix(string obrath, int p) {
    int j = 0;
    for (int i = p; i < obrath.length(); i++)
    {
        if (obrath[i] != obrath[j]) return false;
        ++j;
    }
    return true;
}

//Функция, возвращающая для позиции p длину максимальной подстроки, которая является суффиксом шаблона obrath. 
int suffixLength(string obrath, int p) {
    int m = obrath.length();
    int len = 0;
    int i = p;
    int j = m - 1;
    while (i >= 0 && obrath[i] == obrath[j]) {
        ++len;
        --i;
        --j;
    }return len;
}

//Функция для вычисления сдвигов хороших суффиксов.
vector <size_t> preBmGs(string s) {
    size_t m = s.length();
    vector<size_t> suffshift(m + 1, m);
    //Вычисление Z-Функции
    vector<size_t> z(m, 0);
    for (size_t i = 1, maxZidx = 0, maxZ = 0; i < m; i++) {
        if (i <= maxZ) z[i] = min(maxZ - i + 1, z[i - maxZidx]);
        while (i + z[i] < m && s[m - 1 - z[i]] == s[m - 1 - (i + z[i])]) z[i]++;
        if (i + z[i] - 1 > maxZ) {
            maxZidx = i;
            maxZ = i + z[i] - 1;
        }
    }
    //Формируем таблицу
    for (int i = m - 1; i > 0; i--) suffshift[m - z[i]] = i; //цикл 1
    for (int i = 1, r = 0; i <= m - 1; i++) //цикл 2
    {
        if (i + z[i] == m)
        {
            for (; r <= i; r++)
            {
                if (suffshift[r] == m) suffshift[r] = i;
            }
        }
    }
    return suffshift;
}



list<int> TBM(string text, string obrath) {
    setlocale(0, "");
    int m = obrath.length();
    int n = text.length();
    int i = 0;
    int u = 0;
    int v;
    int turboShift;
    int bCShift;
    int shift = m;
    //answer — массив, в который мы сохраняем индексы, начиная с которых, подстроки текста совпадают с шаблоном
    list<int> answer;
    if (shift == 0)
        return answer;
    //Предварительные вычисления
    int* bmBc = preBmBc(obrath);
    vector<size_t> bmGs = preBmGs(obrath);

    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && obrath[j] == text[i + j]) {
            --j;
            if (u != 0 && j == m - 1 - shift) j -= u;
        }
        if (j < 0) {
            answer.push_back(i);
            shift = bmGs[0];
            u = m - shift;
        }
        else {
            v = m - 1 - j;
            turboShift = u - v;
            bCShift = bmBc[text[i + j] + 1] - m + j + 1;
            shift = turboShift;
            if (shift < bCShift) shift = bCShift;
            if (shift < bmGs[j + 1]) shift = bmGs[j + 1];
            if (shift == bmGs[j + 1])
                u = min((m - shift), v);
            else
            {
                if (turboShift < bCShift)
                    shift = min(shift, (u + 1));
                u = 0;
            }
        }
        i += shift;
    }
    return answer;
}

int main()
{
    setlocale(0, "");
    ifstream file;
    srand(time(0));
    
    file.open("test.txt");
    if (!file.is_open()) { cout << "файл  не найден"; return 0; }
    string obrath, text;
    getline(file, obrath);
    getline(file, text);
    cout << text << endl << obrath << endl;
    list<int> out = TBM(text, obrath);
    int n = out.size();
    for (int i = 0; i < n; i++)
    {
        cout << out.front() << ' ';
        out.pop_front();
    }

    int t = clock();
    cout << endl << "time = " << t << endl;
    return 0;
}