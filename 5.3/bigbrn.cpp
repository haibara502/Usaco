/*
LANG: C++
PROG: bigbrn
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
bool can[maxn][maxn];
int f[maxn][maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
	memset(can, true, sizeof can);
	for (int i = 1; i <= M; ++i)
	{
		int a, b; scanf("%d%d", & a, & b);
		can[a][b] = 0;
	}
}

void getans()
{
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) if (can[i][j])
		{
			f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
			ans = max(ans, f[i][j]);
		}
	cout << ans << endl;
}

int main()
{
	freopen("bigbrn.in", "r", stdin);
	freopen("bigbrn.out", "w", stdout);
	read();
	getans();
}
