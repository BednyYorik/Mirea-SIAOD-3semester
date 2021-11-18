#include <iostream>
#include <string>
#include <locale.h>
#include <ctime>

using namespace std;

bool compar(string text, string obrath) {
    if (text.length() < obrath.length())  return false;
    for (int i = 0; i < obrath.length(); i++)
    {
        if (text[i] != obrath[i]) return false;
    }
    return true;
}

string* task1(string text, string obrath) 
{
    string comparedWord;
    int retLength = 0;
    string retWords;
    cout << text << endl << endl;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            if (text[i - 1] == '!' || text[i - 1] == '?' || text[i - 1] == '.' || text[i - 1] == ',') 
            { 
                comparedWord = comparedWord.substr(0,comparedWord.length() - 1); 
            }
            if (compar(comparedWord, obrath)) 
            { 
                retWords += comparedWord + ' '; retLength++; 
            }
            comparedWord = "";
        }
        else {
            comparedWord += text[i];
        }
    }
    int k = comparedWord.length() - 1;
    if (text[k] == '!' || text[k] == '?' || text[k] == '.' || text[k] == ',') 
    {
        comparedWord = comparedWord.substr(0, comparedWord.length() - 1); 
    }
    if (compar(comparedWord, obrath)) 
    {
        retWords += comparedWord + ' '; retLength++; 
    }
    comparedWord = "";
    cout << retWords;
    string* result = new string[retLength];
    int j = 0;
    for (int i = 0; i < retWords.length(); i++)
    {
        if (retWords[i] == ' ') 
        {
            result[j] = comparedWord;
            j++;
            comparedWord = ""; 
        }
        else comparedWord += retWords[i];
    }
    return result;
}

int main()
{
    setlocale(0, "");
    system("chcp 1251");
    srand(time(0));

    string text;
    string obrat;
    getline(cin, text);
    cin >> obrat;
    task1(text, obrat);

    int t = clock();
    cout << endl << "time = " << t << endl;
}