#include <iostream>

using namespace std;

//Структура узла дерева
struct tnode {
	int info;
	tnode* left;
	tnode* right;
};

//Вывод дерева
void print(tnode* tree, int tabs) {
	if (tree == NULL)
	{
		return;
	}
	else {
		print(tree->left, ++tabs);
		for (int i = 0; i < tabs; ++i) {
			cout << "   ";
		}
		cout << tree->info << endl;
		tabs--;
	}
	print(tree->right, ++tabs);
}

//Симметричный обход дерева
void inftreeprint(tnode* tree) {
	if (tree != NULL) {
		inftreeprint(tree->left);
		cout << tree->info << " ";
		inftreeprint(tree->right);
	}
}

//Обртаный обход дерева
void posttreeprint(tnode* tree) {
	if (tree != NULL) {
		posttreeprint(tree->left);
		posttreeprint(tree->right);
		cout << tree->info << " ";
	}
}

//Добавление элемента дерева
void addnode(int x, tnode*& tree) {
	if (tree == NULL) {
		tree = new tnode;
		tree->info = x;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (tree->info < x) {
		addnode(x, tree->right);
	}
	else {
		addnode(x, tree->left);
	}
}

//Функция вычисления высоты дерева
int height(const tnode* tree) {
	int l, r, h = 0;
	if (tree != NULL) {
		l = height(tree->left);
		r = height(tree->right);
		h = ((l > r) ? l : r) + 1;
	}
	return h;
}

//Функция вычисления суммы значений листьев дерева
int sum_tree(tnode*& tree) {
	int sum = 0;
	if (tree != NULL) {
		sum += sum_tree(tree->left);
		sum += tree->info;
		sum += sum_tree(tree->right);
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, "rus");
	tnode* tree;
	tree = NULL;
	for (int i = 0; i < 10; i++)
	{
		addnode(rand() % 100, tree);
	}
	cout << "\n|------------------ВЫВОД-ДЕРЕВА------------------|\n";
	print(tree, 0);
	cout << "\n\n|------------------СИММЕТРИЧНЫЙ-ОБХОД------------------|\n";
	inftreeprint(tree);
	cout << "\n\n|------------------ОБРАТНЫЙ-ОБХОД------------------|\n";
	posttreeprint(tree);
	cout << "\n\nВысота дерева:" << height(tree);
	cout << "\n\nСумма листьев:" << sum_tree(tree);
}