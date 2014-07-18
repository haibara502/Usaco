/*
LANG: C++
PROG: starry
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110, maxm = 30, X[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
int N, M;
bool p[maxn][maxn];
class Poi
{
	public:
	int x, y;
	Poi(int x = 0, int y = 0):x(x), y(y){};
	void mark()
	{
		p[x][y] = true;
	}
	bool pan()
	{
		return p[x][y];
	}
	void zhuan(int e)
	{
		x += X[e][0], y += X[e][1];
	}
	bool out()
	{
		return ((x < 0) || (y < 0) || (x == N) || (y == M));
	}
} d[maxn * maxn];
char a[maxn][maxn], c[maxn][maxn], ch[maxn][maxn], ans[maxn][maxn];
int b[maxn][maxn];
int Sum[maxm], W[maxm], H[maxm];
int up, down, Left, Right, h, w;
string store[maxm];

void read()
{
	scanf("%d%d", & M, & N);
	for (int i = 0; i < N; ++i) scanf("%s", a[i]);
}

int gs(int i, int j, int v)
{
	d[1] = Poi(i, j);
	d[1].mark();
	a[i][j] = '0';
	b[i][j] = v;
	int closed = 0, open = 1;
	while (closed < open)
	{
		Poi t = d[++closed];
		for (int e = 0; e < 8; ++e)
		{
			Poi d1 = t;
			d1.zhuan(e);
			if (d1.out()) continue;
			if (d1.pan()) continue;
			if (a[d1.x][d1.y] != '1') continue;
			a[d1.x][d1.y] = '0';
			b[d1.x][d1.y] = v;
			d[++open] = d1, d1.mark();
		}
	}
	for (int i = 1; i <= open; ++i)
	{
		up = min(up, d[i].x), down = max(down, d[i].x);
		Left = min(Left, d[i].y), Right = max(Right, d[i].y);
		
	}
	return open;
}

void goutu(int v)
{
	for (int i = up; i <= down; ++i)
		for (int j = Left; j <= Right; ++j) if (b[i][j] == v)
			c[i - up][j - Left] = '1';
			else c[i - up][j - Left] = '0';
}

void fan()
{
	for (int i = 0; i <= h; ++i)
		for (int j = 0; j <= w; ++j) ch[i][j] = c[i][j];
	for (int i = 0; i <= h; ++i)
		for (int j = 0; j <= w; ++j) c[i][j] = ch[i][w - j];
}

void rotate()
{
	for (int i = 0; i <= h; ++i)
		for (int j = 0; j <= w; ++j) ch[i][j] = c[i][j];
	for (int i = 0; i <= h; ++i)
		for (int j = 0; j <= w; ++j) c[j][h - i] = ch[i][j];
	swap(h, w);
}

string zhuan()
{
	string now = "";
	for (int i = 0; i <= h; ++i)
		for (int j = 0; j <= w; ++j) now += c[i][j];
	return now;
}

void ran(int o, int v)
{
	for (int i = up; i <= down; ++i)
		for (int j = Left; j <= Right; ++j) if (b[i][j] == o)
			ans[i][j] = char('a' + v - 1);
}

void getans()
{
	int total = 0, temp = 0;
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) if (a[i][j] == '1')
		{
			//cerr << "i, j : " << i << ' ' << j << endl;
			up = N, down = -1, Left = M, Right = -1;
			int  sum = gs(i, j, ++temp);
			//cerr << sum << endl;
			//cerr << up << ' ' << down << ' ' << Left << ' ' << Right << endl;
			h = down - up, w = Right - Left;
			goutu(temp);
			bool ff = false;
			for (int k = 1; k <= total; ++k)
			{
				if (sum != Sum[k]) continue;
				for (int o = 0; o < 2; ++o)
				{
					fan();
					for (int e = 0; e < 4; ++e)
					{
						//cerr << "---" << endl;
						//for (int i = 0; i <= h; ++i)
						//{
							//for (int j = 0; j <= w; ++j) cerr << c[i][j];
							//cerr << endl;
						//}
						rotate();
						//cerr << "+++" << endl;
						//for (int i = 0; i <= h; ++i)
						//{
							//for (int j = 0; j <= w; ++j) cerr << c[i][j];
							//cerr << endl;
						//}
						//cerr << w << ' ' << W[k] << ' ' << h << ' ' << H[k] << endl;
						if ((w != W[k]) || (h != H[k])) continue;
						if (zhuan() == store[k])
						{
							ff = true; break;
						}
					}
					if (ff) break;
				}
				if (ff) 
				{
					ran(temp, k); break;
				}
			}
			if (!ff) 
			{
				ran(temp, ++total); Sum[total] = sum; store[total] = zhuan(); W[total] = w, H[total] = h;
			}
			//cerr << total << endl;
		}
		
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) if (ans[i][j])
			cout << ans[i][j];
		else cout << '0';
		cout << endl;
	}
}

int main()
{
	freopen("starry.in", "r", stdin);
	freopen("starry.out", "w", stdout);
	read();
	getans();
}
