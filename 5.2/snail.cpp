/*
LANG: C++
PROG: snail
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 125, x[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool b[maxn][maxn], visit[maxn][maxn];
int N, M, ans;

void read()
{
	scanf("%d%d", & N, & M);
	memset(b, false, sizeof b);
	for (int i = 1; i <= M; ++i)
	{
		char w; int a;
		cin >> w >> a;
		b[w - 'A' + 1][a] = true;
	}
}

int can(int i, int j, int direction)
{
	i += x[direction][0], j += x[direction][1];
	if ((i < 1) || (j < 1) || (i > N) || (j > N)) return 1;
	if (b[i][j]) return 1;
	if (visit[i][j]) return 2;
	return 0;
}

void dfs(int i, int j, int direction, int now)
{
//	cerr << i  << ' ' << j << ' ' << direction << ' ' << now << endl;
	visit[i][j] = true;
	ans = max(ans, now);
	if (now == 1)
	{
		if (can(i, j, 1) == 0) dfs(i + x[1][0], j + x[1][1], 1, now + 1);
		if (can(i, j, 2) == 0) dfs(i + x[2][0], j + x[2][1], 2, now + 1);
		return;
	}
	if (can(i, j, direction) == 0) dfs(i + x[direction][0], j + x[direction][1], direction, now + 1);
	else if (can(i, j, direction) != 2)
	{
		if (can(i, j, (direction + 1) % 4) == 0) dfs(i + x[(direction + 1) % 4][0], j + x[(direction + 1) % 4][1], (direction + 1) % 4, now + 1);
		if (can(i, j, (direction + 3) % 4) == 0) dfs(i + x[(direction + 3) % 4][0], j + x[(direction + 3) % 4][1], (direction + 3) % 4, now + 1);
	}
	visit[i][j] = false;
}

void getans()
{
	ans = 0;
	dfs(1, 1, 0, 1);
	cout << ans << endl;
}

int main()
{
	freopen("snail.in", "r", stdin);
	freopen("snail.out", "w", stdout);
	read();
	getans();
}
