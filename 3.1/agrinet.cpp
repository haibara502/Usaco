/*
LANG: C++
PROG: agrinet
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int a[maxn][maxn], choose[maxn];
bool p[maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) 
		for (int j = 1; j <= N; ++j) scanf("%d", & a[i][j]);
}

void getans()
{
	memset(p, false, sizeof p);
	p[1] = true;
	int ans = 0;
	for (int i = 2; i <= N; ++i) choose[i] = a[1][i];
	for (int i = 2; i <= N; ++i)
	{
		int temp1 = 1;
		for	(int j = 1; j <= N; ++j) if (!p[j] && ((temp1 == 1) || (choose[j] < choose[temp1])))
			temp1 = j;
		p[temp1] = true;
		ans += choose[temp1];
		for (int j = 1; j <= N; ++j) choose[j] = min(choose[j], a[temp1][j]);
	}
	cout << ans << endl;
}

int main()
{
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	read();
	getans();
}
