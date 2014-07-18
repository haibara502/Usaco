/*
ID: haibara3
LANG: C++
PROG: barn1
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2010;
int wei[maxn], a[maxn];
int N, S, C;

void read()
{
	scanf("%d%d%d", & N, & S, & C);
	for (int i = 1; i <= C; ++i) scanf("%d", & wei[i]);
	sort(wei + 1, wei + 1 + C);
}

void getans()
{
	for (int i = 1; i < C; ++i) a[i] = wei[i + 1] - wei[i] - 1;
	sort(a + 1, a + C);
	if (N > C) N = C; 
	long long ans = wei[C] - wei[1] + 1;
	for (int i = C - 1; N > 1; --i)
		--N, ans -= a[i];
	cout << ans << endl;
}

int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	read();
	getans();
}
