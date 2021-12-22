#include <iostream>
#include <string>
#include <unordered_map>
#include <windows.h>

using namespace std;

struct node {
    string sym; // Хранение символа
    float pro; // Вероятность появления
    int arr[50]; // Биты
    int top; // Кол-во бит кодирования
}p[50]; // Таблица символов 

typedef struct node node;


// Сжатие методом Шеннона–Фано
void shannon(int l, int h, node p[]) {

    float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
    int i, d, k, j;
    if ((l + 1) == h or l == h or l > h) { // Есди вероятности появления в ветвях равны
        if (l == h or l > h)
            return;
        p[h].arr[++(p[h].top)] = 0; // Всем выше присваиваю +0 в код
        p[l].arr[++(p[l].top)] = 1; // всем ниже присваиваю +1 в код
        return;
    }
    else { // иначе считаем вероятности и находим середину
        for (i = l; i <= h - 1; i++)
            pack1 = pack1 + p[i].pro;
        pack2 = pack2 + p[h].pro;
        diff1 = pack1 - pack2;
        if (diff1 < 0)
            diff1 = diff1 * -1;
        j = 2;
        while (j != h - l + 1) {
            k = h - j;
            pack1 = pack2 = 0;
            for (i = l; i <= k; i++)
                pack1 = pack1 + p[i].pro;
            for (i = h; i > k; i--)
                pack2 = pack2 + p[i].pro;
            diff2 = pack1 - pack2;
            if (diff2 < 0)
                diff2 = diff2 * -1;
            if (diff2 >= diff1)
                break;
            diff1 = diff2;
            j++;
        }
        k++;
        for (i = l; i <= k; i++)
            p[i].arr[++(p[i].top)] = 1;
        for (i = k + 1; i <= h; i++)
            p[i].arr[++(p[i].top)] = 0;

        shannon(l, k, p);
        shannon(k + 1, h, p);
    }
}

// Функция для сортировки символов на основе их вероятности или частоты
void sortByProbability(int n, node p[]) {
    int i, j;
    node temp;
    for (j = 1; j <= n - 1; j++) {
        for (i = 0; i < n - 1; i++) {
            if ((p[i].pro) > (p[i + 1].pro)) {
                temp.pro = p[i].pro;
                temp.sym = p[i].sym;
                p[i].pro = p[i + 1].pro;
                p[i].sym = p[i + 1].sym;
                p[i + 1].pro = temp.pro;
                p[i + 1].sym = temp.sym;
            }
        }
    }
}

// Вывод данных об уникалных символах
void display(int n, node p[]) {

    int i, j;
    cout << "\n\n\n\tСимвол\tВероятность\tКод";
    for (i = 0; i < n; i++) {
        cout << "\n\t" << p[i].sym << "\t\t" << p[i].pro << "\t";
        for (j = 0; j <= p[i].top; j++)
            cout << p[i].arr[j];
    }
}

// Конвертация фразы в сжатый код
string code(string n, node p[], int k) {
    string cod;
    for (int i = 0; i < n.size(); i++) {
        string s(1, n[i]);
        string v = "";
        for (int l = 0; l < k; l++) {
            if (p[l].sym == s) {
                for (int j = 0; j <= p[l].top; j++)
                    v += to_string(p[l].arr[j]);
                cod += v;
            }
        }
        //cod += " ";
    }
    cout << endl << "\nЗакодированная фраза: " << cod << endl;
    return cod;
}

// Декодирование сжатого кода
void decode(string code, node p[], int k) {
    cout << "\nДекодированная -> \t";
    string ch = "";
    string n = "";
    for (int i = 0; i < code.size();) {
        ch += code[i];

        for (int l = 0; l < k; l++) {
            string v = "";
            for (int j = 0; j <= p[l].top; j++)
                v += to_string(p[l].arr[j]);
            if (ch == v) {
                n = p[l].sym;
                cout << n;
                ch = "";
            }

        }
        i++;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int  i, j;
    string n;
    float total = 0;
    string ch;

    cout << "Введите строку\t:";
    getline(cin, n);

    for (i = 0; i < n.size(); i++) {
        ch = n[i];
    }

    int sum = 0;
    int k = 0;
    std::unordered_map<char, int> chars;
    for (const char c : n)
        ++chars[c];
    for (const auto& l : chars) {
        sum += l.second;
        p[k].sym = l.first;
        k++;
    }

    float x[50] = { 0 };
    i = 0;
    for (const auto& l : chars) {
        cout << "\nВероятность символа " << p[i].sym << " : ";
        x[i] = (float)l.second / (float)sum;
        cout << (float)x[i] << " | (кол-во / общее кол-во) " << l.second << " / " << sum;
        p[i].pro = x[i];
        total = total + p[i].pro;

        i++;
    }
    p[i].pro = 1 - total;


    sortByProbability(k, p);
    for (i = 0; i < k; i++)
        p[i].top = -1;

    shannon(0, k - 1, p);

    string cod = code(n, p, k);

    display(k, p);

    cout << endl;
    decode(cod, p, k);
    cout << "\nИсходная -> \t\t" << n;
    cout << "\nСжатие: -> " << 100 - (((float)cod.size() * 100) / ((float)n.size() * 8)) << "%";

    return 0;
}