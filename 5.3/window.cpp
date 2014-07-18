/*
LANG: C++
PROG: window
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int maxn = 110;
class Poi
{
	public:
	char id;
	int x1, y1, x2, y2, ceng, area;
	Poi(char id = ' ', int x11 = 0, int y11 = 0, int x21 = 0, int y21 = 0, int ceng = 0):id(id), x1(x11), y1(y11), x2(x21), y2(y21), ceng(ceng)
	{
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		area = (y2 - y1) * (x2 - x1);
	}
	void print()
	{
		cerr << id << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << ceng << ' ' << area << endl;
	}
} window[maxn];
int sum, total;

void shang(int deep, int x1, int y1, int x2, int y2, int ceng, int o)
{
	if (deep > total)
	{
		sum += (y2 - y1) * (x2 - x1);
		return;
	}
	if (window[deep].ceng <= ceng) 
	{
		shang(deep + 1, x1, y1, x2, y2, ceng, 0);
		return;
	}
	if (!o)
	{
		int l = max(x1, window[deep].x1), r = min(x2, window[deep].x2);
		if (l > r)
		{
			shang(deep + 1, x1, y1, x2, y2, ceng, 0);
			return;
		}
		if (x1 < l) shang(deep + 1, x1, y1, l, y2, ceng, 0);
		if (x2 > r) shang(deep + 1, r, y1, x2, y2, ceng, 0);
		shang(deep, l, y1, r, y2, ceng, 1);
	}
	else
	{
		int l = max(y1, window[deep].y1), r = min(y2, window[deep].y2);
		if (l > r)
		{
			shang(deep + 1, x1, y1, x2, y2, ceng, 0);
			return;
		}
		if (y1 < l) shang(deep + 1, x1, y1, x2, l, ceng, 0);
		if (y2 > r) shang(deep + 1, x1, r, x2, y2, ceng, 0);
	}
}

void read()
{
	int top = 0, down = 0;
	total = 0;
	char w, id;
	int x1, y1, x2, y2;
	while (cin >> w)
	{
		switch (w)
		{
			case 'w':
				scanf("(%c, %d, %d, %d, %d)", & id, & x1, & y1, & x2, & y2);
				window[++total] = Poi(id, x1, y1, x2, y2, ++top);
				break;
			case 't':
				scanf("(%c)", & id);
				for (int i = 1; i <= total; ++i) if (window[i].id == id)
				{
					window[i].ceng = ++top;
					break;
				}
				break;
			case 'b':
				scanf("(%c)", & id);
				for (int i = 1; i <= total; ++i) if (window[i].id == id)
				{
					window[i].ceng = --down;
					break;
				}
				break;
			case 'd':
				scanf("(%c)", & id);
				for (int i = 1; i <= total; ++i) if (window[i].id == id)
				{
					window[i] = window[total--];
					break;
				}
				break;
			case 's':
//				for (int i = 1; i <= total; ++i) window[i].print();
				scanf("(%c)", & id);
				for (int i = 1; i <= total; ++i) if (window[i].id == id)
				{
					sum = 0;
					shang(1, window[i].x1, window[i].y1, window[i].x2, window[i].y2, window[i].ceng, 0);
					cout << fixed << setprecision(3) << (double)sum / window[i].area * 100 << endl;
					break;
				}
		}
	}
}

int main()
{
	freopen("window.in", "r", stdin);
	freopen("window.out", "w", stdout);
	read();
}
