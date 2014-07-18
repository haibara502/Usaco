/*
LANG: C++
PROG: sort3
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1100;
int N;
int a[maxn], sum[maxn], pos[maxn], an[maxn][maxn];

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

void getans()
{
	memset(sum, 0, sizeof sum);
	memset(pos, 0, sizeof pos);
	for (int i = 1; i <= N; ++i) ++sum[a[i]];
	for (int i = 1; i <= 3; ++i)
	{
		sum[i] += sum[i - 1];
		for (int j = sum[i - 1] + 1; j <= sum[i]; ++j) pos[j] = i;
	}
	memset(an, 0, sizeof an);
	for (int i = 1; i <= N; ++i) ++an[a[i]][pos[i]];
	//cout << an[1][2] << ' ' << an[1][3] << ' ' << an[2][1] << ' ' << an[2][3] << ' ' << an[3][1] << ' ' << an[3][2] << endl;
	int ans = 0;
	ans += (min(an[1][2], an[2][1]) + min(an[1][3], an[3][1]) + min(an[2][3], an[3][2])) + abs(an[1][2] - an[2][1]) + abs(an[1][3] - an[3][1]);
	cout << ans << endl;
}

int main()
{
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	read();
	getans();
}
