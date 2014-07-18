/*
LANG: C++
PROG: frac1
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

void dfs(int l1, int r1, int l2, int r2)
{
	int mid1 = l1 + l2, mid2 = r1 + r2;
	if (mid2 > N) return;
	
	dfs(l1, r1, mid1, mid2);
	printf("%d/%d\n", mid1, mid2);
	dfs(mid1, mid2, l2, r2);
}

void getans()
{
	cout << "0/1" << endl;
	dfs(0, 1, 1, 1);
	cout << "1/1" << endl;
}

int main()
{
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	read();
	getans();
}
