/*
LANG:C++
PROG: race3
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 55, maxm = 210;
int d[maxn], an[maxn], status[maxn];
bool p[maxn];
int s[maxm], next[maxm], g1[maxn];
int N, total;

void init(int i, int j)
{
	s[++total] = j; next[total] = g1[i]; g1[i] = total;
}

void read()
{	
	total = 0;
	for (int i = 0; ; ++i)
	{
		int j;
		scanf("%d", & j);
		if (j == -1) break;
		N = i;
		for (; j != -2; scanf("%d", & j))
			init(i, j);
	}
}

int gs(int start, int end, int v)
{
	memset(p, false, sizeof p);
	d[1] = start; p[start] = true; status[start] |= v;
	int closed = 0, open = 1;
	while (closed < open)
	{
		int t = d[++closed];
	//	cerr << "t:" << t << endl;
		if (t == end) continue;
		for (int temp = g1[t]; temp; temp = next[temp]) if (!p[s[temp]])
		{
		//	cerr << s[temp] << ' ';
			d[++open] = s[temp], p[s[temp]] = true;
			status[s[temp]] |= v;
		}
	//	cerr << endl;
	}
	return open;
}

void getans()
{
	int ans = 0;
	for (int i = 1; i < N; ++i)
	{
		memset(status, 0, sizeof status);
		gs(0, i, 1);
		if (!(status[N] & 1)) an[++ans] = i;
	}
	if (!ans) cout << 0 << endl;
	else
	{
		cout << ans << ' ';
		for (int i = 1; i < ans; ++i) cout << an[i] << ' ';
		if (ans) cout << an[ans] << endl;
	}
	
	int ans1 = 0;
	for (int i = 1; i <= ans; ++i)
	{
//		cerr << "an[i] : " << an[i] << endl;
		memset(status, 0, sizeof status);
		gs(0, an[i], 1);
		gs(an[i], N, 2);
		bool ff = true;
		for (int j = 0; j <= N; ++j) if ((j != an[i]) && (status[j] == 3))
		{
			ff = false; break;
		}
		if (ff) an[++ans1] = an[i];
	}
	if (!ans1) cout << 0 << endl;
	else
	{
		cout << ans1 << ' ';
		for (int i = 1; i < ans1; ++i) cout << an[i] << ' ';
		if (ans1) cout << an[ans1] << endl;
	}
}

int main()
{
	freopen("race3.in", "r", stdin);
	freopen("race3.out", "w", stdout);
	read();
	getans();
}
