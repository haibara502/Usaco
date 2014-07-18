/*
PROG: castle
LANG: C++
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int a[maxn][maxn];
int size[maxn * maxn], fa[maxn * maxn];
int N, M;

void read()
{
	scanf("%d%d", & M, & N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) scanf("%d", & a[i][j]);
}

inline int number(int i, int j)
{
	return (i - 1) * M + j;
}

inline int get(int v)
{
	if (fa[v] == v) return v;
	return fa[v] = get(fa[v]);
}

void getans()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) fa[number(i, j)] = number(i, j), size[number(i, j)] = 1;
		
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j < M; ++j) if (!(a[i][j] & (1 << 2)))
		{
			int x = number(i, j), y = number(i, j + 1);
			x = get(x), y = get(y);
			if (x != y)
				size[y] += size[x], fa[x] = y;
		}
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= M; ++j) if (!(a[i][j] & (1 << 1)))
		{
			int x = get(number(i, j)), y = get(number(i - 1, j));
			if (x != y)
				size[y] += size[x], fa[x] = y;
		}
		
	int total = 0, max_size = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) if (fa[number(i, j)] == number(i, j))
			++total, max_size = max(max_size, size[number(i, j)]);
	cout << total << endl << max_size << endl;
	
	max_size = 0;
	int wayx = -1, wayy = -1;
	char wayc = ' ';
	for (int j = 1; j <= M; ++j)
		for (int i = N; i >= 1; --i)
		{
			int y = get(number(i, j));
			if (i > 1)
			{
				int x = get(number(i - 1, j));
				if (x != y)
				{
					int sum = size[x] + size[y];
					if (sum > max_size)
						max_size = sum, wayx = i, wayy = j, wayc = 'N';
				}
			}
			if (j < M)
			{
				int x = get(number(i, j + 1));
				if (x != y)
				{
					int sum = size[x] + size[y];
					if (sum > max_size)
						max_size = sum, wayx = i, wayy = j, wayc = 'E';
				}
			}
		}
	cout << max_size << endl << wayx << ' ' << wayy << ' ' << wayc << endl;
}

int main()
{
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	read();
	getans();
}
