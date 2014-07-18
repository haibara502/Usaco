/*
LANG: C++
PROG: fence9
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, P;

void read()
{
	scanf("%d%d%d", & N, & M, & P);
}

int calc(int l1, int r1, int l2, int r2, int level, int eq)
{
	if (l1 == l2) 
		if (eq) return l1 + 1;
		else return l1 - 1;
	long double k = (long double)(r2 - r1) / (l2 - l1);
	long double b = r1 - k * l1;
	//cerr << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << k << ' ' << b << endl;
	long double ans = (level - b) / k;
	if (eq == 1) return (int)ans + eq;
	else if (((int)ans) == ans) return ans - 1; 
	else return ans;
}

void getans()
{
	long long ans = 0;
	for (int i = 1; i < M; ++i)
	{
		int l = calc(0, 0, N, M, i, 1), r = calc(P, 0, N, M, i, 0);
		ans += r - l + 1;
	}
	cout << ans << endl;
}

int main()
{
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);
	read();
	getans();
}
