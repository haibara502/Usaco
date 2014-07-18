/*
LANG: C++
PROG: concom
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
class Poi
{
	public:
		int x, y;
		Poi(int x = 0, int y = 0):x(x), y(y){}
		bool operator <(const Poi & Q) const
		{
			if (x != Q.x) return x < Q.x;
			return y < Q.y;
		}
}d[maxn * maxn];
int own[maxn][maxn];
int N;
bool p[maxn][maxn];

void read()
{
	scanf("%d", & N);
	memset(own, 0, sizeof own);
	for (int i = 1; i <= N; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", & a, & b, & c);
		own[a][b] += c;
	}
}

void getans()
{
	int closed = 0, open = 0;
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j) if ((i != j) && (own[i][j] > 50))
			d[++open] = Poi(i, j), p[i][j] = true;
	for (int i = 1; i <= 100; ++i) p[i][i] = true;
	while (closed < open)
	{
		Poi t = d[++closed];
		for (int k = 1; k <= 100; ++k) 
		{
			own[t.x][k] += own[t.y][k];
			if ((own[t.x][k] > 50) && (!p[t.x][k]))
				d[++open] = Poi(t.x, k), p[t.x][k] = true;
		}
	}
	sort(d + 1, d + 1 + open);
	for (int i = 1; i <= open; ++i) cout << d[i].x << ' ' << d[i].y << endl;
}

int main()
{
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	read();
	getans();
}
