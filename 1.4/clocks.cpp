/*
ID: haibara3
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200010;
bool p[4][4][4][4][4][4][4][4][4], move[10];
class Poi
{
	int a[9];
	public:
	Poi()
	{
		for (int i = 0; i < 9; ++i) a[i] = 0;
	}
	void read()
	{
		for (int i = 0; i < 9; ++i)
		{
			int a1; scanf("%d", & a1);
			a[i] = (a1 / 3) % 4;
		}
	}
	void rotate(int v)
	{
		memset(move, false, sizeof move);
		switch (v)
		{
			case 1:
				move[0] = move[1] = move[3] = move[4] = true;
				break;
			case 2:
				move[0] = move[1] = move[2] = true;
				break;
			case 3:
				move[1] = move[2] = move[4] = move[5] = true;
				break;
			case 4:
				move[0] = move[3] = move[6] = true;
				break;
			case 5:
				move[1] = move[3] = move[4] = move[5] = move[7] = true;
				break;
			case 6:
				move[2] = move[5] = move[8] = true;
				break;
			case 7:
				move[3] = move[4] = move[6] = move[7] = true;
				break;
			case 8:
				move[6] = move[7] = move[8] = true;
				break;
			case 9:
				move[4] = move[5] = move[7] = move[8] = true;	
		}
		for (int i = 0; i < 9; ++i) if (move[i]) a[i] = (a[i] + 1) % 4;
	}
	bool check()
	{
		for (int i = 0; i < 9; ++i) if (a[i]) return false;
		return true;
	}
	void mark()
	{
		p[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]] = true;
	}
	bool pan()
	{
		return p[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]];
	}
} d[maxn];
int d2[maxn], way[maxn], before[maxn];

void read()
{
	d[1].read();
}

void getans()
{
	d[1].mark();
	int closed = 0, open = 1;
	while (closed < open)
	{
		Poi t = d[++closed];
		for (int i = 1; i < 10; ++i)
		{
			Poi d1 = t;
			d1.rotate(i);
			if (!d1.pan())
				d[++open] = d1, d1.mark(), before[open] = closed, way[open] = i;
			if (d1.check())
			{
				int len = 0;
				for (; open != 1; open = before[open]) d2[++len] = way[open];
				for (int i = len; i > 1; --i) cout << d2[i] << ' ';
				cout << d2[1] << endl;
				return;
			}
		}
	}
}

int main()
{
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	read();
	getans();
}
