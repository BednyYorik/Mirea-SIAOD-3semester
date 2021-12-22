#include <iostream>
#include <ctime>
using namespace std; 

int Dynamic_Triangle(int a[][100], int n)				// Алгоритм поиска наибольшей суммы методом Динамического программирования  
{	
	for (int i = n - 2; i >= 0; i--) {					// Проход по каждому уровню
		for (int j = 0; j <= i; j++) {					// Проход по элементам уровня
			if (a[i + 1][j] > a[i + 1][j + 1]) {
				a[i][j] += a[i + 1][j];
			}
			else {
				a[i][j] += a[i + 1][j + 1];
			}
		}
	}
	return a[0][0];
}

int Recursion_Triangle(int a[][100],int n, int row, int column, int total)				// Алгоритм поиска наибольшей суммы методом Рекурсии
{
	if (row == n - 1) {
		return total + a[row][column];
	}
	return max(Recursion_Triangle(a, n, row + 1, column, total + a[row][column]), Recursion_Triangle(a, n, row + 1, column + 1, total + a[row][column]));
}

int main() {
		
	setlocale(LC_ALL, "RUS");							//Локализация консоли
	
	// ИНициализация переменных
	int a[100][100];									// Треугольник
	int n;												// Уровни треугольника
	
	cin >> n;
	
	// Заполнение треугольника
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	//Вывод результатов
	unsigned int start_time = clock();
	cout << "Метод решения \"в лоб\" - Рекурсия: " << Recursion_Triangle(a, n, 0, 0, 0) << endl; // Результат работы алгоритма "в лоб"
	unsigned int end_time = clock();
	cout << (end_time - start_time) << "мс\n";
	start_time = clock();
	cout << "Метод решения - Динамическое программирование: " << Dynamic_Triangle(a, n) << endl; // Результат работы алгоритма методом динамического программирования 
	end_time = clock();
	cout << (end_time - start_time) << "мс\n";
	return 0;
}