/*
LANG: C++
PROG: money
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 30, maxm = 10010;
int a[maxn];
long long f[maxm];
int V, N;

void read()
{
	scanf("%d%d", & V, & N);
	for (int i = 1; i <= V; ++i) scanf("%d", & a[i]);
}

void getans()
{
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = 1; i <= V; ++i)
		for (int j = a[i]; j <= N; ++j)
			f[j] += f[j - a[i]];
	cout << f[N] << endl;
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	read();
	getans();
}
