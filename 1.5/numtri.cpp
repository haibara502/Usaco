/*
LANG: C++
PROG: numtri
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1100;
int a[maxn][maxn], f[maxn][maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j) scanf("%d", & a[i][j]);
}

void getans()
{
	f[1][1] = a[1][1];
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j) f[i][j] = max(f[i][j], f[i - 1][j]);
		for (int j = 2; j <= i; ++j) f[i][j] = max(f[i][j], f[i - 1][j - 1]);
		for (int j = 1; j <= i; ++j) f[i][j] += a[i][j];
	}
	int ans = f[N][1];
	for (int i = 2; i <= N; ++i) ans = max(ans, f[N][i]);
	cout << ans << endl;
}

int main()
{
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	read();
	getans();
}
