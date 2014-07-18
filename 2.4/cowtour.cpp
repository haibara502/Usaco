/*
LANG: C++
PROG: cowtour
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int maxn = 160;
class Poi
{
	public:
	int x, y;
} a[maxn];
bool can[maxn][maxn];
long double dis[maxn][maxn], away[maxn];
int N;
char ss[maxn];

long long sqr(int v)
{
	return (long long)v * v;
}

void read()
{
	scanf("%d", & N);
	for (int i = 0; i < N; ++i) scanf("%d%d", & a[i].x, & a[i].y);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", ss);
		for (int j = 0; j < N; ++j) if (ss[j] == '1') can[i][j] = true;
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) 
		{
			dis[i][j] = 1e50;
			if (can[i][j]) dis[i][j] = sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y));
		}
}

void getans()
{
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i) if (dis[i][k] != 1e50)
			for (int j = 0; j < N; ++j)	if (dis[k][j] != 1e50 && (i != j))
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	for (int i = 0; i < N; ++i) 
	{
		away[i] = 0;
		for (int j = 0; j < N; ++j) if (dis[i][j] != 1e50 && dis[i][j] > away[i] && (i != j))
			away[i] = dis[i][j];
	}
	
	long double ans1 = 0;
	for (int i = 0; i < N; ++i) ans1 = max(ans1, away[i]);
	
	long double ans = 1e50;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) if (dis[i][j] == 1e50 && (i != j))
			ans = min(ans, away[i] + away[j] + sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y)));
			
	ans = max(ans, ans1);
	cout << fixed << setprecision(6) << ans << endl;
}

int main()
{
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	read();
	getans();
}
