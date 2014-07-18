/*
LANG: C++
PROG: schlnet
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110, maxm = maxn  * maxn;
int s[maxm], next[maxm], g1[maxn];
int dfn[maxn], low[maxn], sta[maxn];
bool visit[maxn], ins[maxn];
int in[maxn], out[maxn], belong[maxn];
int N, total, star, tuo;

void init(int i, int j)
{
	s[++total] = j; next[total] = g1[i]; g1[i] = total;
}

void read()
{
	scanf("%d", & N);
	total = 1;
	for (int i = 1; i <= N; ++i)
	{
		int j; scanf("%d", & j);
		for (; j; scanf("%d", & j))
			init(i, j);
	}
}

void tarjan(int v)
{
	dfn[v] = low[v] = ++total;
	sta[++star] = v;
	ins[v] = visit[v] = true;
	for (int temp = g1[v]; temp; temp = next[temp]) if (!visit[s[temp]])
	{
		tarjan(s[temp]);
		low[v] = min(low[v], low[s[temp]]);
	}
	else if (ins[s[temp]])
		low[v] = min(low[v], dfn[s[temp]]);
	if (low[v] == dfn[v])
	{
		++tuo;
		while (ins[v])
		{
			belong[sta[star]] = tuo;
			ins[sta[star--]] = false;
		}
	}
}

void getans()
{
	total = tuo = star = 0;
	int sum = 0;
	for (int i = 1; i <= N; ++i) 
		if (!visit[i])	tarjan(i);
	if (tuo == 1)
	{
		cout << 1 << endl << 0 << endl;
		return;
	}
	
	for (int i = 1; i <= N; ++i)
		for (int temp = g1[i]; temp; temp = next[temp]) if (belong[i] != belong[s[temp]])
			++in[belong[s[temp]]], ++out[belong[i]];
			
	int ans1 = 0;
	for (int i = 1; i <= tuo; ++i) if (!in[i]) ++ans1;
	cout << ans1 << endl;
	
	int ans2 = 0;
	for (int i = 1; i <= tuo; ++i) if (!out[i]) ++ans2;
	cout << max(ans1, ans2) << endl;
}

int main()
{
	freopen("schlnet.in", "r", stdin);
	freopen("schlnet.out", "w", stdout);
	read();
	getans();
}
