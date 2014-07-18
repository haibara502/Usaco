/*
LANG: C++
PROG: fact4
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

void read()
{
	scanf("%d", & N);
}

void getans()
{
	long long ans = 1;
	for (int i = 2; i <= N; ++i)
	{
		int v = i;
		for (; v % 5 == 0; v /= 5) ans /= 2;
		ans = (ans * v) % 1000000000LL;
	}
	cout << ans % 10 << endl;
}

int main()
{
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	read();
	getans();
}
