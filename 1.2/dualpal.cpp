/*
ID: haibara3
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int d[maxn];
int N, S;

void read()
{
	scanf("%d%d", & N, & S);
}

bool zhuan(int v, int base)
{
	int len = 0;
	for (; v; v /= base)
		d[++len] = v % base;
	for (int i = 1; len - i + 1 >= i; ++i) if (d[i] != d[len - i + 1]) return false;
	return true;
}

void getans()
{
	for (int i = S + 1; N; ++i)
	{
		int cnt = 0;
		for (int j = 2; j <= 10; ++j) if (zhuan(i, j)) ++cnt;
		if (cnt >= 2)
		{
			cout << i << endl;
			--N;
		}	
	}
}

int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	read();
	getans();
}
