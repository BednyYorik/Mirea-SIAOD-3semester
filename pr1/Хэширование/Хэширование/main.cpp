#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

int TABLE_SIZE = 10;


struct Reader {
	int _number = 0;
	string _group = "";
	string _name = "";
};


class Hash {
	list<Reader>* table;

public:
	Hash() {
		table = new list<Reader>[TABLE_SIZE];
	}

	int hashFunction(int x) {
		return (x % 10);
	}

	void insertData() {
		int number;
		string group, name;


		cout << "Input number: ";
		cin >> number;
		cout << "Input student's group: ";
		cin >> group;
		cout << "Input name: ";
		cin >> name;

		int i = hashFunction(number);
		Reader tmp;
		tmp._number = number;
		tmp._group = group;
		tmp._name = name;

		table[i].push_back(tmp);
	}

	void deleteData() {
		int studentNumber;
		cout << "Enter number to delete: ";
		cin >> studentNumber;

		int index = hashFunction(studentNumber);

		list<Reader>::iterator i;
		for (i = table[index].begin(); i != table[index].end(); ++i) {
			if (i->_number == studentNumber) {
				break;
			}
		}

		if (i != table[index].end()) {
			cout << "Student " << i->_name << " has been removed from list!\n";
			table[index].erase(i);
		}
		else {
			cout << "Student number is not in this list!\n";
		}
	}

	void search() {
		int readerNumber;
		cout << "Enter number to find: ";
		cin >> readerNumber;
		int index = hashFunction(readerNumber);

		list<Reader>::iterator i;
		bool check = false;
		for (i = table[index].begin(); i != table[index].end(); ++i) {
			if (i->_number == readerNumber) {
				check = true;
				cout << "Record found:\n";
				cout << "\tNumber\t\tGroup\t\t\tName\n";
				cout << "\t"  << i->_number << "\t\t" << i->_group << "\t\t" << i->_name << "\n";
			}
		}

		if (!check) {
			cout << "Cannot find this student!\n";
		}
	}

	void displayHash() {
		for (int i = 0; i < 10; ++i) {
			cout << i << ": ";
			for (auto x : table[i]) {
				cout << "  -->  " << x._number << "|" << x._group << "|" << x._name;
			}
			cout << endl;
		}
	}

	void makeFile() {
		ofstream fout("Hash.txt");
		if (!fout)
		{
			cout << "File write Error" << endl;
		}
		for (int i = 0; i < 10; ++i) {
			fout << i << ": ";
			for (auto x : table[i]) {
				fout << "  -->  " << x._number << "|" << x._group << "|" << x._name;
			}
			fout << endl;
		}
	}
};

int main() {
	Hash t = Hash();
	cout << "------------------------Menu------------------------\n";
	cout << "[1] - Insert new record\n";
	cout << "[2] - Find a student\n";
	cout << "[3] - Delete a student\n";
	cout << "[4] - Display hash table\n";
	cout << "[0] - Exit program\n";
	cout << "----------------------------------------------------\n";
	int size = 0;
	int choice = 0;
	do
	{
		cout << "Input your choice: ";
		cin >> choice;
		cout << "----------------------------------------------------\n";

		switch (choice)
		{
		case 1:
			int n;
			cout << "Input number of record to insert: ";
			cin >> n;
			size += n;
			if (TABLE_SIZE == size) TABLE_SIZE*=2;
			for (int i = 0; i < n; ++i) {
				cout << "-----------------------------------------\n";
				t.insertData();
			}
			cout << "Done!\n";
			break;

		case 2:
			t.search();
			break;
		case 3:
			t.deleteData();
			break;
		case 4:
			t.displayHash();
			break;
		case 0:
			t.makeFile();
			cout << "Thanks for using program!\n";
			break;
		default:
			break;
		}

		cout << "----------------------------------------------------\n";
	} while (choice != 0);


	system("pause");
	return 0;
}