#include <iostream>
#include <bitset>

using namespace std;

void run11() {	// Задание 1.а
	unsigned char mask = 1; //1 = 0000 0001 - 8-разрядная маска
	unsigned char a = 255; // 255 = 1111 1111
	cout << int(a) << endl;
	a = a & (~(mask << 4)); // 239 = 1110 1111
	cout << int(a);
	cout << endl;
}
void run12() {	// Задание 1.б
	unsigned char mask = 1; //1 = 0000 0001 - 8-разрядная маска
	unsigned char b = 128; // 128 = 1000 0000
	cout << int(b) << endl;
	b = b | (mask << 6); // 192 = 1100 0000
	cout << int(b);
	cout << endl;
}
void run13() {	// Задание 1.в
	unsigned int x = 25;
	const int n = sizeof(int) * 8; // размерность int в битах (4*8=32)
	unsigned maska = (1 << n - 1); // сдвиг единицы на место самого старшего бита
	cout << "Начальный вид маски: " << bitset<n>(maska) << endl;
	cout << "Результат: ";
	for (int i = 1; i <= n; i++) {
		// Вывод x в битовом представлении
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1;
	}
	cout << endl;
}

int main() {
	setlocale(0, "");
	// Выбор задания
	run13();
}

