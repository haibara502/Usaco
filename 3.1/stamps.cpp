/*
LANG: C++
PROG: stamps
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000101, maxm = 51;
int a[maxm], f[maxn];
int K, N;

void read()
{
	scanf("%d%d", & K, & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

void getans()
{
	memset(f, -1, sizeof f);
	f[0] = 0;
	
	for (int i = 1; i <= 2000100; ++i)
	{
		for (int j = 1; j <= N; ++j) if ((i >= a[j]) && (f[i - a[j]] != -1))
			f[i] = min((unsigned)f[i], (unsigned)(f[i - a[j]] + 1));
		if ((f[i] == -1) || (f[i] > K)) 
		{
			cout << i - 1 << endl;
			break;
		}
	}
}

int main()
{
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	read();
	getans();
}
