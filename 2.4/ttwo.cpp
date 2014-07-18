/*
LANG: C++
PROG: ttwo
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 12, d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
char a[maxn][maxn];
class Poi
{
	public:
	int x, y;
	Poi(int x = 0, int y = 0):x(x), y(y){}
	bool operator ==(const Poi & Q) const
	{
		return ((x == Q.x) && (y == Q.y));
	}
	bool operator !=(const Poi & Q) const
	{
		return ((x != Q.x) || (y != Q.y));
	}
	bool out()
	{
		return ((x < 0) || (y < 0) || (x >= 10)|| (y >= 10));
	}
	bool zhang()
	{
		return a[x][y] == '*';
	}
	void jin(int v)
	{
		x += d[v][0], y += d[v][1];
	}	
};
bool p[maxn][maxn][4][maxn][maxn][4];

void read()
{
	for (int i = 0; i < 10; ++i) scanf("%s", a[i]);
}

void zou(Poi & Q, int & v)
{
	Poi p = Q; p.jin(v);
	if (!p.out() && !p.zhang())
	{
		Q = p;
		return;
	}
	v = (v + 1) % 4;
}

void getans()
{
	Poi pf, pc;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if (a[i][j] == 'F')
				pf.x = i, pf.y = j;
			else if (a[i][j] == 'C')
				pc.x = i, pc.y = j;
	memset(p, false, sizeof p);
	p[pf.x][pf.y][0][pc.x][pc.y][0] = true;
	int df = 0, dc = 0;
	int time = 0;
	
	while (pc != pf)
	{
		++time;
		zou(pf, df);
		zou(pc, dc);
		if (pc == pf)
		{
			cout << time << endl;
			return;
		}
		if (p[pf.x][pf.y][df][pc.x][pc.y][dc]) 
		{
			cout << 0 << endl;
			return;
		}
		p[pf.x][pf.y][df][pc.x][pc.y][dc] = true;
	}
}

int main()
{
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	read();
	getans();
}
