/*
LANG: C++
PROG: rect1
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
class Poi
{
	public:
	int x1, y1, x2, y2, color;
	void read()
	{
		scanf("%d%d%d%d%d", & x1, & y1, & x2, & y2, & color);
	}
	Poi(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int color = 1):x1(x1), y1(y1), x2(x2), y2(y2), color(color){}
} rec[maxn];
class Seg
{
	public:
	int x1, y1, x2, y2;
	Seg(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0):x1(x1), y1(y1), x2(x2), y2(y2){}
	void print()
	{
		cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	}
} d[maxn * 100];
int N, A, B, total;
int an[2600];

void read()
{
	scanf("%d%d%d", & A, & B, & N);
	total = 0;
	for (int i = 1; i <= N; ++i)
		rec[i].read();
	rec[0] = Poi(0, 0, A, B);
}

void add(int x1, int y1, int x2, int y2, int color)
{
//	cerr << "Add: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << color << endl;
	an[color] += (y2 - y1) * (x2 - x1);
	d[++total] = Seg(x1, y1, x2, y2);
}

void shang(int deep, int x1, int y1, int x2, int y2, int color, int o)
{
//	cerr << deep << ' ' << total << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << color << ' ' << o << endl;
//	d[deep].print();
	if (deep > N) 
	{
		add(x1, y1, x2, y2, color);
		return;
	}
	if (!o)
	{
		int l = max(x1, rec[deep].x1), r = min(x2, rec[deep].x2);
		if (l > r)
		{
			shang(deep + 1, x1, y1, x2, y2, color, 0);
			return;
		}
		if (x1 < l) shang(deep + 1, x1, y1, l, y2, color, 0);
		if (x2 > r) shang(deep + 1, r, y1, x2, y2, color, 0);
		shang(deep, l, y1, r, y2, color, 1);
	}
	else
	{
		int l = max(y1, rec[deep].y1), r = min(y2, rec[deep].y2);
		if (l > r)
		{
			shang(deep + 1, x1, y1, x2, y2, color, 0);
			return;
		}
		if (y1 < l) shang(deep + 1, x1, y1, x2, l, color, 0);
		if (y2 > r) shang(deep + 1, x1, r, x2, y2, color, 0);
	}
}

void getans()
{
	total = 0;
	memset(an, 0, sizeof an);
	for (int i = N; i >= 0; --i)
		shang(i + 1, rec[i].x1, rec[i].y1, rec[i].x2, rec[i].y2, rec[i].color, 0);
	//cerr << total << endl;
	for (int i = 1; i <= 2500; ++i) if (an[i])
		cout << i << ' ' << an[i] << endl;
}

int main()
{
	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);
	read();
	getans();
}
