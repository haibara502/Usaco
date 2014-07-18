/*
LANG: C++
PROG: rockers
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int last[maxn], f[maxn][maxn][maxn];
int N, T, M;

void read()
{
	scanf("%d%d%d", & N, & T, & M);	
	for (int i = 1; i <= N; ++i) scanf("%d", & last[i]);
}

void getans()
{
	memset(f, -1, sizeof f);
	f[0][1][0] = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 1; j <= M; ++j)
			for (int k = 0; k <= T; ++k) if (f[i][j][k] != -1)
			{
				f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k]);
				if (k + last[i + 1] <= T)
					f[i + 1][j][k + last[i + 1]] = max(f[i + 1][j][k + last[i + 1]], f[i][j][k] + 1);
				if ((j < M) && (k))
					f[i + 1][j + 1][last[i + 1]] = max(f[i + 1][j + 1][last[i + 1]], f[i][j][k] + 1);
			}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			for (int k = 0; k <= T; ++k)
				ans = max(ans, f[i][j][k]);
	cout << ans << endl;
}

int main()
{
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	read();
	getans();
}
