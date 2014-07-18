/*
LANG: C++
PROG: heritage
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 256;
string zhong, qian;
char l[maxn], r[maxn];

void read()
{
	cin >> zhong >> qian;
}

char search(int l1, int r1, int l2, int r2)
{
	//cerr << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
	if (l1 > r1) return ' ';
	char w = qian[l2];
	for (int i = l1; i <= r1; ++i) if (zhong[i] == w)
	{
		l[w] = search(l1, i - 1, l2 + 1, l2 + i - l1);
		r[w] = search(i + 1, r1, r2 - r1 + i + 1, r2);
	}
	return w;
}

void dfs(char w)
{
	if (l[w] != ' ') dfs(l[w]);
	if (r[w] != ' ') dfs(r[w]);
	cout << w;
}

void getans()
{
	char root = search(0, zhong.size() - 1, 0, qian.size() - 1);
	dfs(root);
	cout << endl;
}

int main()
{
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	read();
	getans();
}
