/*
LANG: C++
PROG: tour
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 110;
int f[maxn][maxn];
bool con[maxn][maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
	map<string, int> cities;
	for (int i = 1; i <= N; ++i)
	{
		string name;
		cin >> name;
		cities[name] = i;
	}
	memset(con, false, sizeof con);
	for (int i = 1; i <= M; ++i)
	{
		string one, two;
		cin >> one >> two;
		int a = cities[one], b = cities[two];
		con[a][b] = con[b][a] = true;
	}
}

void getans()
{
	for (int i = 2; i <= N; ++i) if (con[1][i])
		f[1][i] = f[i][1] = 2;
		
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) if (f[i][j])
			for (int k = max(i, j) + 1; k <= N; ++k) 
			{
				if (con[i][k]) f[k][j] = max(f[k][j], f[i][j] + 1);
				if (con[j][k]) f[i][k] = max(f[i][k], f[i][j] + 1);
			}
		
	int ans = 1;
	for (int i = 1; i <= N; ++i) if (con[i][N])
		ans = max(ans, max(f[N][i], f[i][N]));
	cout << ans << endl;
}

int main()
{
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	read();
	getans();
}
