/*
LANG: C++
PROG: fence6
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int sum[maxn][2], x[maxn][2][10], length[maxn];
bool p[maxn];
int N, ans;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
	{
		int a; scanf("%d", & a);
		scanf("%d%d%d", & length[a], & sum[a][0], & sum[a][1]);
		for (int j = 0; j < 2; ++j)
			for (int k = 1; k <= sum[a][j]; ++k)
				scanf("%d", & x[a][j][k]);
	}
}

bool find(int t, int v)
{
	for (int i = 1; i <= sum[t][0]; ++i)
		if (x[t][0][i] == v) return true;
	return false;
}

void dfs(int v, int o, int now, int begin, int before)
{
	if (now >= ans) return;
	
	if ((v == begin) && (now))
	{
		ans = now;
		return;
	}
	
	p[v] = true;
	for (int j = 1; j <= sum[v][o]; ++j)
	{
		int t = x[v][o][j];
		if ((!p[t]) || (t == begin))
			dfs(t, find(t, v), now + length[v], begin, v);
	}
	p[v] = false;
}

void getans()
{
	ans = 1073741824;
	
	for (int i = 1; i <= N; ++i)
	{
		memset(p, false, sizeof p);
		dfs(i, 0, 0, i, -1);
	}
	
	cout << ans << endl;
}

int main()
{
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);
	read();
	getans();
}
