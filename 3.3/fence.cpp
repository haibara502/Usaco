/*
LANG: C++
PROG: fence
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 510;
int show[maxn], s[maxn][maxn], du[maxn], an[maxn], number[maxn];
int N, M, ans;

int Int(int v)
{
	if (show[v]) return show[v];
	show[v] = ++N;
	number[N] = v;
	return show[v];
}

void read()
{
	scanf("%d", & M);
	N = 0;
	memset(show, 0, sizeof show);
	for (int i = 1; i <= M; ++i)
	{
		int a, b; scanf("%d%d", & a, & b);
		++s[a][b], ++s[b][a];
		++du[a], ++du[b];
	}
}

void print()
{
	for (int i = ans; i; --i) cout << an[i] << endl;
}

void dfs(int v)
{
	for (int i = 1; i <= 500; ++i) if (s[v][i])
	{
		--s[v][i], --s[i][v];
		dfs(i);
	}
	an[++ans] = v;
}

void getans()
{
	ans = 0;
	for (int i = 1; i <= 500; ++i) if (du[i] & 1)
	{
		dfs(i);
		print();
		return;
	}
	for (int i = 1; i <= 500; ++i) if (du[i])
	{
		dfs(i);
		print();
		return;
	}
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	read();
	getans();
}
