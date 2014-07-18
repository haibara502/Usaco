/*
LANG: C++
PROG: stall4
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 210;
int x[maxn][maxn], an[maxn];
bool visit[maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", & x[i][0]);
		for (int j = 1; j <= x[i][0]; ++j) scanf("%d", & x[i][j]);
	}
}

bool find(int v)
{
	for (int i = 1; i <= x[v][0]; ++i) if (!visit[x[v][i]])
	{
		visit[x[v][i]] = true;
		if ((!an[x[v][i]]) || (find(an[x[v][i]])))
		{
			an[x[v][i]] = v;
			return true;
		}
	}
	return false;
}

void getans()
{
	int ans = 0;
	
	memset(an, 0, sizeof an);
	for (int i = 1; i <= N; ++i)
	{
		memset(visit, false, sizeof visit);
		if (find(i)) ++ans;
	}
	cout << ans << endl;
}

int main()
{
	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);
	read();
	getans();
}
