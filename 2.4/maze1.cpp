/*
LANG: C++
PROG: maze1
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110, w[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int N, M;
bool p[maxn][maxn], can[maxn][maxn][4];
class Poi
{
	public:
	int x, y;
	Poi(int x = 0, int y = 0):x(x), y(y) {}
	bool pan()
	{
		return p[x][y];
	}
	void mark()
	{
		p[x][y] = true;
	}
	bool out()
	{
		return (!x || !y || (x > N) || (y > M));
	}
	void jin(int v)
	{
		x += w[v][0], y += w[v][1];
	}
} d[maxn * maxn];
int temp[maxn][maxn], an[maxn][maxn];
char ss[maxn];

void read()
{
	scanf("%d%d", & M, & N);
	gets(ss);
	memset(can, false, sizeof can);
	for (int i = 1; i <= 2 * N + 1; ++i)
	{
		gets(ss);
		for (int j = 1; j <= 2 * M + 1; ++j)
		{
			char w = ss[j - 1];
			if ((i & 1) == (j & 1)) continue;
			if (w != ' ') continue;
			if (i & 1)
			{
				if (i > 1) can[i / 2][j / 2][2] = true;
				if (i < 2 * N + 1) can[i / 2 + 1][j / 2][0] = true;
			}
			else
			{
				if (j > 1) can[i / 2][j / 2][1] = true;
				if (j < 2 * M + 1) can[i / 2][j / 2 + 1][3] = true;
			}
		}
	}
}

void gs()
{
	int closed = 0, open = 1;
	memset(p, false, sizeof p);
	d[1].mark();
	temp[d[1].x][d[1].y] = 1;
	while (closed < open)
	{
		Poi t = d[++closed];
		for (int v = 0; v < 4; ++v) if (can[t.x][t.y][v])
		{
			Poi t1 = t; t1.jin(v);
			if (t1.out() || t1.pan()) continue;
			t1.mark();
			d[++open] = t1;
			temp[t1.x][t1.y] = temp[t.x][t.y] + 1;
		}
	}
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) 
			an[i][j] = min(an[i][j], temp[i][j]);
}

void getans()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) an[i][j] = N * M + 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) 
			for (int v = 0; v < 4; ++v)
			{
				Poi t = Poi(i, j);
				if (can[t.x][t.y][v])
				{
					t.jin(v);
					if (t.out())
					{
						d[1] = Poi(i, j);
						gs();
					}
				}
			}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) if (an[i][j] > ans)
			ans = an[i][j];
	cout << ans << endl;
}

int main()
{
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	read();
	getans();
}
