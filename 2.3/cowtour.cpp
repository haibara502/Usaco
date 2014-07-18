#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 160;
class Poi
{
	public:
	int x, y;
} a[maxn];
bool can[maxn][maxn];
long double dis[maxn][maxn];
int N;

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
		for (int j = 0; j < N; ++j) can[i][j] = true;
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
			for (int j = 0; j < N; ++j)	if (dis[k][j] != 1e50)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 0; i < N; ++i) 
	{
		away[i] = 0;
		for (int j = 0; j < N; ++j) if (dis[i][j] != 1e50 && dis[i][j] > away[i])
			away[i] = dis[i][j];
	}
	
	long double ans = 1e50;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) if (dis[i][j] == 1e50)
			ans = min(ans, away[i] + away[j] + sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y));
	cout << ans << endl;
}

int main()
{
	read();
	getans();
}
