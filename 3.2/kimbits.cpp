/*
ID: haibara3
LANG: C++
PROG: kimbits
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50;
int N, L;
long long M;
int way[maxn], f[maxn][maxn], g[maxn][maxn];

void read()
{
	cin >> N >> L >> M;
}

void dfs(int deep, int need, long long remain)
{
	if (need > deep) need = deep;
//	cerr << deep << ' '  << need << ' ' << remain << endl;
	if (deep == 0)
	{
		for (int i = N; i; --i) cout << way[i];
		cout << endl;
		return;
	}
//	cerr << g[deep - 1][need] << endl;
	if (g[deep - 1][need] >= remain)
	{
		way[deep] = 0;
		dfs(deep - 1, need, remain);
	}
	else
	{
		way[deep] = 1;
		dfs(deep - 1, need - 1, remain - g[deep - 1][need]);
	}
}

void getans()
{
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for (int j = 0; j <= N; ++j) g[0][j] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= L; ++j)
		{
			f[i][j] = f[i - 1][j];
			if (j) f[i][j] += f[i - 1][j - 1];
			g[i][j] = f[i][j];
			if (j) g[i][j] += g[i][j - 1];
		}
		for (int j = L + 1; j <= N; ++j) g[i][j] = g[i][j - 1];
	}
	dfs(N, L, M);
}

int main()
{
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);
	read();
	getans();
}
