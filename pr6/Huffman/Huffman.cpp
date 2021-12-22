#include "Huffman.h"
#define encode_output "output_encode.txt"
#define decode_output "output_decode.txt"
#define filename_input "input.txt"

using namespace std;


/* Создание алфавита */
string get_repeat(string text)
{
	string abc;
	bool exit_flag = 0;
	abc.push_back(text[0]);
	for (int i = 1; i < text.size(); i++)
	{
		exit_flag = 0;
		for (int j = 0; j < abc.size(); j++)
		{
			if (abc[j] == text[i])						//Если в нашем алфавите уже есть такая буква
			{
				exit_flag = 1;							//Выходим, если нашли такую букву
				break;
			}
		}
		if (exit_flag == 1)								//Если мы находили букву ранее
		{
			continue;									//Переходим на следующую итерацию для след. буквы
		}
		else											//Если буква найдена не была
		{
			abc.push_back(text[i]);
			continue;
		}
	}
	return abc;
}

/* Получение массива частоты использования символов */
void get_frequency(string text, int* frequencies, string abc)
{
	for (int i = 0; i < abc.size(); i++)
	{
		frequencies[i] = 0;
	}
	for (int j = 0; j < abc.size(); j++)
	{
		for (int i = 0; i < text.size(); i++)
		{
			if (abc[j] == text[i])
			{
				frequencies[j]++;
			}
		}
	}
}

/* Ввод входого текста с клавиатуры */
string get_input()
{
	string text;
	cout << "Message: ";
	getline(std::cin, text);
	cout << endl;
	return text;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string text;
	text = get_input();									//Ввод с клавиатуры
	

	/* Получаем массив частот */
	string abc = get_repeat(text);
	int* frequencies = new int[abc.size()];
	get_frequency(text, frequencies, abc);

	cout << "Text is: " << text << endl;

	cout << "Alphabet: " << abc << endl;
	cout << "Size of alphabet: " << abc.size() << endl;
	cout << "Frequencies: " << endl;
	for (int i = 0; i < abc.size(); i++)
	{
		cout << abc[i] << " - " << frequencies[i] << endl;
	}
	cout << endl;

	/* Обработка исключения: один символ */
	bool flag_ex = 0;
	if (abc.size() < 2)
	{
		flag_ex = !flag_ex;
	}

	/* Кодирование */
	huffman_coding encoding;
	cout << endl << "Character: Code-word" << endl;
	encoding.HuffmanCodes(abc, frequencies, flag_ex);
	encoding.encode_text(text);

	string temp = encoding.get_encode();

	cout << endl << "Code-string: " << temp;
	encoding.output_file(encode_output, true);

	/* Раскодирование */
	temp = encoding.decode_text(temp, flag_ex);
	cout << endl << "Decode-string: " << temp << endl;
	encoding.output_file(decode_output, false);

	return 0;
}