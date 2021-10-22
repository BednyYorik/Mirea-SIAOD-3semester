#include <iostream>
#include <bitset>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

void createText() {
	ofstream file;
	file.open("text.txt");
	for (int i = 9999999; i >= 1000000; i--) {
		file << i << " ";
	};
	file.close();
}

void run31() {	// Задания 3.а и 3.б
	unsigned char mask = 1;
	auto begin = chrono::high_resolution_clock::now();
	// Старт таймера
	ofstream output;
	ifstream file;
	file.open("text.txt");
	output.open("output.txt");

	vector<unsigned char> m;
	for (int i = 0; i < 10000000 / 8; i++) {
		m.push_back(0);
	}
	int tmp;
	while (file >> tmp) {
		m[tmp / 8] = m[tmp / 8] | (mask << (tmp % 8));
	}

	for (int i = 0; i < 10000000 / 8; i++) {
		for (int j = 0; j < 8; j++) {
			// Просмотр элемента вектора
			tmp = (m[i] & mask) >> j;
			if (tmp == 1) {
				output << 8 * i + j << " ";
			}
			mask = mask << 1;
		}
		mask = 1; // Сброс маски
	}
	// Остановка таймера
	auto end = chrono::steady_clock::now();
	m.shrink_to_fit();
	cout << m.capacity() << " Байт" << endl;
	cout << m.capacity() / 1024 << " КБ" << endl;
	cout << m.capacity() / 1024 / 1024 << " МБ";
	cout << endl;
	chrono::duration<double, std::milli> elapsed_ms = end - begin;
	cout << "Time: " << elapsed_ms.count() << " ms\n";
	cout << endl;
	//
}
// Выбор задания
int main() {
	setlocale(0, "");
	run31();
}
