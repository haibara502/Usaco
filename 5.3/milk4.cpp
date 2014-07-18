/*
LANG: C++
PROG: milk4
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int v[maxn], an[maxn], way[maxn];
int Q, N, ans;
bool ff;

void read()
{
	scanf("%d", & Q);
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & v[i]);
}

void dfs(int deep, int begin, int need, int now)
{
	if (deep > need)
	{
		if (now == 0) 
		{
			for (int i = 1; i < deep; ++i) an[i] = way[i];
			ff = true;
		}
		return;
	}
	if (begin > N) return;
	for (int i = begin; i <= N; ++i)
	{
		if (an[deep] < v[i]) return;
		way[deep] = v[i];
		for (int j = 1; v[i] * j <= now; ++j)
			dfs(deep + 1, i + 1, need, now - j * v[i]);
	}
}

void getans()
{
	sort(v + 1, v + 1 + N);
	ans = 0;
	for (int i = 1; i <= N; ++i) an[i] = 1073741824;
	for (int number = 1; number <= N; ++number)
	{
		dfs(1, 1, number, Q);
		if (ff) 
		{
			ans = number; break;
		}
	}
	cout << ans ;
	for (int i = 1; i <= ans; ++i) cout << ' ' << an[i];
	cout << endl;
}

int main()
{
	freopen("milk4.in", "r", stdin);
	freopen("milk4.out", "w", stdout);
	read();
	getans();
}
