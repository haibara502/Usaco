/*
LANG: C++
PROG: game1
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1100;
int a[maxn], f[maxn][maxn], sum[maxn][maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

void getans()
{
	for (int i = 1; i <= N; ++i) f[i][i] = sum[i][i] = a[i];
	for (int l = 1; l < N; ++l)
		for (int i = 1; i <= N; ++i)
		{
			int j = i + l;
			if (j > N) break;
			sum[i][j] = sum[i + 1][j] + a[i];
			f[i][j] = max(sum[i + 1][j] - f[i + 1][j] + a[i], sum[i][j - 1] - f[i][j - 1] + a[j]);
		}
	cout << f[1][N] << ' ' << sum[1][N] - f[1][N] << endl;
}

int main()
{
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	read();
	getans();
}
