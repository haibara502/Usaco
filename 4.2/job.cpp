/*
LANG: C++
PROG: job
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int sum[2], needT[2][maxn], cost[2][maxn], now[maxn];
int N;

void read()
{
	scanf("%d%d%d", & N, & sum[0], & sum[1]);
	for (int i = 0; i < 2; ++i)
		for (int j = 1; j <= sum[i]; ++j) scanf("%d", & needT[i][j]);
}

void sort(int v)
{
	for (int i = 1; i < N; ++i)
	{
		int j = i;
		for (int k = i + 1; k <= N; ++k) if (cost[v][j] > cost[v][k])
			j = k;
		swap(cost[v][i], cost[v][j]);
	}
}

void getans()
{
	for (int i = 0; i < 2; ++i)
	{
		memset(now, 0, sizeof now);
		for (int j = 1; j <= N; ++j)
		{
			cost[i][j] = 1073741823;
			int choose = -1;
			for (int k = 1; k <= sum[i]; ++k) if (now[k] + needT[i][k] < cost[i][j])
				cost[i][j] = now[k] + needT[i][k], choose = k;
			now[choose] += needT[i][choose];
		}
		
		sort(i);
		//for (int j = 1; j <= N; ++j) cerr << i << ' ' << j << ' ' << cost[i][j] << ' ';
		//cerr << endl;
	}
	
	int ans = cost[0][1] + cost[1][N];
	for (int i = 2; i <= N; ++i) 
		ans = max(ans, cost[0][i] + cost[1][N - i + 1]);
	cout << cost[0][N] << ' ' << ans << endl;
}

int main()
{
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	read();
	getans();
}
