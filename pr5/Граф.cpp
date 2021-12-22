#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[100000];
int rk[100000];

struct edge
{
	int a, b, len;
	bool operator<(const edge& other)
	{
		return len < other.len;
	}
};

void init_dsu()
{
	for (int i = 0; i < 10000; i++)
	{
		p[i] = i;
		rk[i] = 1;
	}
}

int get_root(int v)
{
	if (p[v] == v)return v;
	else return p[v] = get_root(p[v]);
}

bool merge(int a, int b) {
	int ra = get_root(a);
	int rb = get_root(b);
	if (ra == rb) return false;
	else
	{
		if (rk[a] < rk[b]) p[ra] = rb;
		else if (rk[rb] < rk[ra]) p[rb] = ra;
		else
		{
			p[ra] = rb;
			rk[rb]++;
		}
		return true;
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	vector<edge> edges;
	vector<edge>news;
	int m;
	cout << "Колличество граней:" << endl;
	cin >> m;
	cout << "Грани (начало, конец, вес):" << endl;
	for (int i = 0; i < m; i++)
	{
		edge e;
		cin >> e.a >> e.b >> e.len;
		edges.push_back(e);
	}
	sort(edges.begin(), edges.end());
	int mst_weight = 0;
	init_dsu();
	for (edge e : edges)
	{
		if (merge(e.a, e.b))
		{
			mst_weight += e.len;
			news.push_back(e);
		}
	}

	cout << endl << "Остовной граф" << endl;
	for (int i = 0; i < news.size(); i++)
	{
		cout << news[i].a << " " << news[i].b << " " << news[i].len << endl;
	}
	cout << "Минимальный вес связующего дерева: " << mst_weight << endl;
	/*
	* base input
	* m = 12
	7 6 36
	7 5 25
	7 4 16
	7 3 9
	7 2 4 
	7 1 1
	1 2 20
	1 6 23
	4 5 17
	4 3 3
	6 5 28
	2 3 15
	*/

}