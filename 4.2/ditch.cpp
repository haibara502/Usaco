/*
LANG: C++
PROG: ditch
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 210, maxm = 500, cs = 1073741824;
int s[maxm], next[maxm], g1[maxn], f[maxm];
int dis[maxn], vh[maxn];
int N, M, total, S, T;

void init(int i, int j, int k)
{
	s[++total] = j; next[total] = g1[i]; g1[i] = total; f[total] = k;
	s[++total] = i; next[total]  =g1[j]; g1[j] = total; f[total] = 0;
}

void read()
{
	scanf("%d%d", & M, & N);
	total = 1;
	for (int i = 1; i <= M; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", & a, & b, & c);
		init(a, b, c);
	}
}

int find(int v, int total)
{
//	cerr << v << ' ' << total << endl;
	if ((v == T)  || !total) return total;
	int Min = T, l = total;
	for (int temp = g1[v]; temp; temp = next[temp]) if (f[temp])
	{
		if (dis[s[temp]] == dis[v] - 1)
		{
			int d1 = find(s[temp], min(l, f[temp]));
			f[temp] -= d1, f[temp ^ 1] += d1;
			l -= d1;
			if (dis[1] >= T) return total - l;
			if (!l) break;
		}
		Min = min(Min, dis[s[temp]] + 1);
	}
	if (total == l)
	{
		if (!--vh[dis[v]]) dis[1] = T;
		++vh[dis[v] = Min];
	}
	return total - l;
}

void getans()
{
	memset(dis, 0, sizeof dis);
	memset(vh, 0, sizeof vh);
	S = 1, T = N;
	vh[0] = T;
	int ans = 0;
	while (dis[1] < T) ans += find(S, cs);
	cout << ans << endl;
}

int main()
{
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);
	read();
	getans();
}
