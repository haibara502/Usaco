/*
LANG: C++
PROG: inflate
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10010;
int points[maxn], minutes[maxn], f[maxn];
int N, M;

void read()
{
	scanf("%d%d", & M, & N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", & points[i], & minutes[i]);
}

void getans()
{
	memset(f, 0, sizeof f);
	for (int i = 1; i <= N; ++i)
		for (int j = minutes[i]; j <= M; ++j) 
			f[j] = max(f[j], f[j - minutes[i]] + points[i]);
	int ans = 0;
	for (int i = 1; i <= M; ++i) ans = max(ans, f[i]);
	cout << ans << endl;
}

int main()
{
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	read();
	getans();
}
