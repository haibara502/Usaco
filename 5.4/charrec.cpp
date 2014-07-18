/*
LANG: C++
PROG: charrec
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1210, cs = 1073741824;
const char letter[30] = " abcdefghijklmnopqrstuvwxyz";
char Std[30][22][22], a[maxn][22];
int cha[30][30][maxn];
int cost[maxn][30], rec[maxn][30];
int f[maxn], g[maxn], an[maxn];
int N;

void read()
{
	freopen("font.in", "r", stdin);
	int a1; scanf("%d", & a1);
	for (int i = 1; i <= 27; ++i)
		for (int j = 1; j <= 20; ++j)
			for (int k = 1; k <= 20; ++k)
				cin >> Std[i][j][k];
			
	freopen("charrec.in", "r", stdin);
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= 20; ++j) cin >> a[i][j];
}

void update(int i, int v, int total, int j)
{
	if (total < cost[i][v])
		cost[i][v] = total, rec[i][v] = j;
}

void getans()
{
	for (int i = 1; i <= 27; ++i)
		for (int j = 1; j <= 20; ++j)
			for (int k = 1; k <= N; ++k) 
			{
				cha[i][j][k] = 0;
				for (int l = 1; l <= 20; ++l) cha[i][j][k] += (Std[i][j][l] != a[k][l]);
			}
			
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 19; j <= 21; ++j) cost[i][j] = cs;
			for (int j = 1; j <= 27; ++j)
		
		if (i + 18 <= N)
			for (int j = 1; j <= 27; ++j)
			{
				int total = 0;
				for (int k = 2; k <= 20; ++k) total += cha[j][k][i + k - 2];
				update(i, 19, total, j);
				for (int k = 2; k <= 20; ++k)
				{
					total -= cha[j][k][i + k - 2];
					total += cha[j][k - 1][i + k - 2];
					update(i, 19, total, j);
				}
			}
		
		if (i + 19 <= N)
			for (int j = 1; j <= 27; ++j)
			{
				int total = 0;
				for (int k = 1; k <= 20; ++k) total += cha[j][k][i + k - 1];
				update(i, 20, total, j);
			}
			
		if (i + 20 <= N)
			for (int j = 1; j <= 27; ++j)
			{
				int total = 0;
				for (int k = 1; k <= 20; ++k)
					if (k == 1) total += cha[j][1][i];
					else total += cha[j][k][i + k];
				update(i, 21, total, j);
				for (int k = 2; k <= 20; ++k)
				{
					total += cha[j][k][i + k - 1];
					total -= cha[j][k][i + k];
					update(i, 21, total, j);
				}
			}
	}
	
	f[0] = 0;
	for (int i = 1; i <= N; ++i) f[i] = cs;
	
	for (int i = 1; i <= N; ++i)
		for (int j = 19; j <= 21; ++j) if ((i >= j) && (f[i - j] != cs))
			if (f[i - j] + cost[i - j + 1][j] < f[i])
				f[i] = f[i - j] + cost[i - j + 1][j],
				g[i] = j;
				
	int ans = 0;
	for (int i = N; i > 1; i -= g[i])
		an[++ans] = rec[i - g[i] + 1][g[i]];
		
	for (int i = ans; i >= 1; --i)
		cout << letter[an[i] - 1];
	cout << endl;	
}

int main()
{
	freopen("charrec.out", "w", stdout);
	read();
	getans();
}
