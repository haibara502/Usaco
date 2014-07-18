/*
LANG: C++
PROG: betsy
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10, X[4][2] = {0, 1, -1, 0, 0, -1, 1, 0};
bool p[maxn][maxn];
int N, ans;

void read()
{
	scanf("%d", & N);
}

int count(int x, int y)
{
	int cnt = 0;
	for (int e = 0; e < 4; ++e) if (!p[x + X[e][0]][y + X[e][1]])
		++cnt;
	return cnt;
}

void dfs(int deep, int x, int y)
{
	if (x == N)
		if (p[N][N] == false) return;
	if (y == N)
		if (p[1][N] == false) return;
	if ((x == N) && (y == 1))
	{
		if (deep == N * N) ++ans;
		return;
	}
	
	if ((p[x + 1][y] && p[x - 1][y] && !p[x][y + 1] && !p[x][y - 1]) || (!p[x + 1][y] && !p[x - 1][y] && p[x][y + 1] && p[x][y - 1])) return;
	
	int xx = -1, yy = -1, total = 0;
	for (int e = 0; e < 4; ++e)
	{
		int x1 = x + X[e][0], y1 = y + X[e][1];
		if (p[x1][y1] || ((x1 == N) && (y1 == 1))) continue;
		if (count(x1, y1) < 2)
			++total, xx = x1, yy = y1;
	}	
	
	if (total > 1) return;
	else if (total == 1)
	{
		p[xx][yy] = true;
		dfs(deep + 1, xx, yy);
		p[xx][yy] = false;
	}
	else
		for (int e = 0; e < 4; ++e)
		{
			int x1 = x + X[e][0], y1 = y + X[e][1];
			if (p[x1][y1]) continue;
			p[x1][y1] = true;
			dfs(deep + 1, x1, y1);
			p[x1][y1] = false;
		}
}

void getans()
{
	ans = 0;
	memset(p, false, sizeof p);
	for (int i = 1; i <= N; ++i)
		p[0][i] = p[N + 1][i] = p[i][0] = p[i][N + 1] = true;
	p[1][1] = true;
	dfs(1, 1, 1);
	cout << ans << endl;
}

int main()
{
	freopen("betsy.in", "r", stdin);
	freopen("betsy.out", "w", stdout);
	read();
	getans();
}
