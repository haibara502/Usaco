/*
LANG: C++
ID: haibara3
PROG: nocows
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
 
const int maxn = 110, maxm = 210, cs = 9901;
int f[maxn][maxm], g[maxn][maxm];
int N, K;
 
void read()
{
	scanf("%d%d", & N, & K);
}

void getans()
{
	f[1][1] = 1;
	for (int i = 2; i <= K; ++i)
	{
		for (int j = 1; j <= N; j += 2)
			for (int k = 1; k <= j - 1 - k; k += 2)
			{
				int c = 2;
				if (k == j - 1 - k) c = 1;
				f[i][j] += c * (g[i - 2][k] * f[i - 1][j - 1 - k] + f[i - 1][k] * g[i - 2][j - 1 - k] + f[i - 1][k] * f[i - 1][j - 1 - k]);
				f[i][j] %= cs;
			}
		for (int k = 0; k <= N; ++k)
		{
			g[i - 1][k] += f[i - 1][k] + g[i - 2][k];
			g[i - 1][k] %= cs;
		}
	}
	cout << f[K][N] << endl;
}

int main() 
{
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	read();
	getans();
}
