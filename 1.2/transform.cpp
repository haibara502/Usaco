/*
ID: haibara3
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20;
char a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 0; i < N; ++i) scanf("%s", a[i]);
	for (int i = 0; i < N; ++i) scanf("%s", b[i]);
}

bool can(int v)
{
	switch (v)
	{
		case 1:
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					c[j][N - i - 1] = a[i][j];
			break;
		case 2:
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					c[N - i - 1][N - j - 1] = a[i][j];
			break;
		case 3:
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					c[N - j - 1][i] = a[i][j];
			break;
		case 4:
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					c[i][N - j - 1] = a[i][j];
			break;
		case 5:
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					c[i][N - j - 1] = a[i][j];
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					a[i][j] = c[i][j];
			for (int i = 1; i < 4; ++i) if (can(i))
				return true;
			return false; 
	}
	/*
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) cerr << c[i][j];
		cerr << endl;
	}
	cerr << endl;
	*/
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) if (b[i][j] != c[i][j]) return false;
	return true;
}

void getans()
{
	for (int i = 1; i < 7; ++i) if (can(i))
	{
		cout << i << endl;
		return;
	}
	cout << 7 << endl;
}

int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	read();
	getans();
}
