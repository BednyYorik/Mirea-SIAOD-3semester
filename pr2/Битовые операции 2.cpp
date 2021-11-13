#include <iostream>
#include <bitset>
#include <vector>


using namespace std;

void run21() {	// Задание 2.а
	unsigned char mask = 1; //1 = 0000 0001 - 8-разрядная маска
	// 5 6 3 7 0
	unsigned char m = 0;
	int tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		m = m | (mask << (tmp));
	}
	//cout << bitset<8>(m) << endl;
	for (int i = 0; i <= 7; i++) {
		if ((mask & m) != 0) {
			cout << i << " ";
		}
		mask = mask << 1;
	}
}
void run22() {	// Задание 2.б
	unsigned long long mask = 1;
	// 53 45 32 0 63
	unsigned long long m = 0;
	int tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		m = m | (mask << (tmp));
	}
	//cout << bitset<64>(m) << endl;
	for (int i = 0; i <= 63; i++) {
		if ((mask & m) != 0) {
			cout << i << " ";
		}
		mask = mask << 1;
	}
}

void run23() {	// Задание 2.в
	unsigned char mask = 1;
	// 53 45 32 0 63
	vector<unsigned char> m;
	for (int i = 0; i <= 63; i++) {
		m.push_back(0);
	}
	int tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		m[tmp / 8] = m[tmp / 8] | (mask << (tmp % 8));
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// Рассмотр элемента вектора
			tmp = (m[i] & mask) >> j;
			if (tmp == 1) {
				cout << 8 * i + j << " ";
			}
			mask = mask << 1;
		}
		mask = 1; // Сброс маски
	}
}
// Выбор задания
int main() {
	setlocale(0, "");
	run21();
}
