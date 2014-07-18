/*
LANG: C++
PROG: butter
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 810, maxm = 3000, cs = 1073741823;
int s[maxm], next[maxm], g1[maxn], f[maxm];
int sum[maxn], di[maxn], d[1000100];
bool p[maxn];
int N, P, C, total;

void init(int a, int b, int c)
{
	s[++total] = b; next[total] = g1[a]; g1[a] = total; f[total] = c;
}

void read()
{
	scanf("%d%d%d", & N, & P, & C);
	memset(sum, 0, sizeof sum);
	for (int i = 1; i <= N; ++i)
	{
		int a; scanf("%d", & a);
		++sum[a];
	}
	total = 0;
	memset(next, 0, sizeof next);
	for (int i = 1; i <= C; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", & a, & b, & c);
		init(a, b, c);
		init(b, a, c);
	}
}

void getans()
{
	int ans = cs;
	for (int i = 1; i <= P; ++i)// if (sum[i])
	{
		for (int j = 1; j <= P; ++j) di[j] = cs, p[j] = false;
		d[1] = i, p[i] = true, di[i] = 0;
		int closed = 0, open = 1;
		while (closed < open)
		{
			int t = d[++closed];
			for (int temp = g1[t]; temp; temp = next[temp]) if (di[t] + f[temp] < di[s[temp]])
			{
				di[s[temp]] = di[t] + f[temp];
				if (!p[s[temp]])
					p[s[temp]] = true, d[++open] = s[temp];
			}
			p[t] = false;
		}
		int total = 0;
		for (int j = 1; j <= P; ++j) total += sum[j] * di[j];
		ans = min(ans, total);
	}
	cout << ans << endl;
}


int main()
{
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	read();
	getans();
}
