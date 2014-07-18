/*
LANG: C++
PROG: range
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 310;
int a[maxn][maxn], an[maxn], f[maxn][maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			char w; cin >> w;
			a[i][j] = (w == '1');
		}
}

void getans()
{
	memset(an, 0, sizeof an);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			f[i][j] = 0;
			if (a[i][j])
				f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
			++an[f[i][j]];
		}
	for (int i = N; i; --i)
		an[i - 1] += an[i];
	for (int i = 2; i <= N; ++i)
	{
		if (!an[i]) break;
		cout << i << ' ' << an[i] << endl;
	}
}

int main()
{
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	read();
	getans();
}
