/*
LANG: C++
PROG: camelot
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 50, T[8][2] = {1, 2, 2, 1, 1, -2, -2, 1, -1, 2, 2, -1, -1, -2, -2, -1}, S[10][2] = {0, 0, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -2, -2}, cs = 1073741820;
int dis[maxn][maxn], dist[27][41][27][41], que[41 * 27][27][41];
bool p[maxn][maxn];
int N, M, people;
class Poi
{
	public:
	int x, y;
	Poi(int x = 0, int y = 0):x(x), y(y){}
	void mark()
	{
		p[x][y] = true;
	}
	bool pan()
	{
		return p[x][y];
	}
	void tiao(int e)
	{
		x += T[e][0], y += T[e][1];
	}
	bool out()
	{
		return ((x < 1) || (y < 1) || (x > N) || (y > M));
	}
} d[maxn * maxn], pos[maxn * maxn], gw;

void set(Poi & Q, char w, int a)
{
	Q = Poi(w - 'A' + 1, a);
}

void read()
{
	scanf("%d%d", & M, & N);
	char w; int a;
	cin >> w >> a;
	set(gw, w, a);
	people = 0;
	while (cin >> w >> a)
	{
		++people;
		set(pos[people], w, a);
	}
}

void gs()
{
	memset(p, false, sizeof p);
	d[1].mark(); 
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) dis[i][j] = cs;
	dis[d[1].x][d[1].y] = 0;
	int closed = 0, open = 1;
	while (closed < open)
	{
		Poi t = d[++closed];
		for (int e = 0; e < 8; ++e)
		{
			Poi d1 = t;
			d1.tiao(e);
			if (d1.out()) continue;
			if (d1.pan()) continue;
			d1.mark();
			dis[d1.x][d1.y] = dis[t.x][t.y] + 1;
			d[++open] = d1;
		}
	}
}

void getans()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			d[1] = Poi(i, j);
			gs();
			for (int k = 1; k <= N; ++k)
				for (int l = 1; l <= M; ++l) 
					dist[i][j][k][l] = dis[k][l];
		}
		
	memset(que, -1, sizeof que);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) 
		{
			int sum = 0;
			for (int k = 1; k <= people; ++k) 
				if (dist[pos[k].x][pos[k].y][i][j] == cs) 
				{
					sum = -1; break;
				}
				else sum += dist[pos[k].x][pos[k].y][i][j];
			if (sum == -1) continue;
			for (int k = 1; k <= people; ++k)
				que[k][i][j] = sum - dist[pos[k].x][pos[k].y][i][j];
		}
	
	int ans = cs;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{	
			for (int k = 1; k <= people; ++k) if (que[k][i][j] != -1)
				for (int e = 0; e < 10; ++e) if (!Poi(gw.x + S[e][0], gw.y + S[e][1]).out())
				{
					int total = dist[pos[k].x][pos[k].y][gw.x + S[e][0]][gw.y + S[e][1]] + max(abs(S[e][0]), abs(S[e][1])) + dist[gw.x + S[e][0]][gw.y + S[e][1]][i][j];
					if (total > cs) continue;
					total += que[k][i][j];
					if (total < ans)
						ans = total;
				}
			int total = max(abs(gw.x - i), abs(gw.y - j));
			for (int k = 1; k <= people; ++k) 
				if (dist[pos[k].x][pos[k].y][i][j] == cs)
				{
					total = -1; break;
				}
				else total += dist[pos[k].x][pos[k].y][i][j];
			if (total != -1) ans = min(ans, total);
		}
				
	cout << ans << endl;
}

int main()
{
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);
	read();
	getans();
}
