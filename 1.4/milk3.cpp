/*
ID: haibara3
LANG: C++
PROG: milk3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 21 * 21 * 21;
int full[3], d2[21];
bool p[21][21][21], show[21];
class Poi
{
	public:
		int a[3];
		Poi(int x = 0, int y = 0, int z = 0)
		{
			a[0] = x, a[1] = y, a[2] = z;
		}
		void rotate(int i, int j)
		{
			if (a[i] <= full[j] - a[j]) a[j] += a[i], a[i] = 0;
			else a[i] -= full[j] - a[j], a[j] = full[j];
		}
		void mark()
		{
			p[a[0]][a[1]][a[2]] = true;
		}
		bool pan()
		{
			return p[a[0]][a[1]][a[2]];
		}
} d[maxn];

void read()
{
	memset(p, false, sizeof p);
	scanf("%d%d%d", & full[0], & full[1], & full[2]);
	d[1] = Poi(0, 0, full[2]);
	d[1].mark();
}

void getans()
{
	int closed = 0, open = 1;
	while (closed < open)
	{
		Poi t = d[++closed];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) if (i != j)
			{
				Poi d1 = t;
				d1.rotate(i, j);
				if (!d1.pan())
					d[++open] = d1, d1.mark();
			}
	}
	memset(show, false, sizeof show);
	for (int i = 1; i <= open; ++i) if (d[i].a[0] == 0) show[d[i].a[2]] = true;
	int len = 0;
	for (int i = 0; i <= full[2]; ++i) if (show[i]) d2[++len] = i;
	for (int i = 1; i < len; ++i) cout << d2[i] << ' ';
	cout << d2[len] << endl;
}

int main()
{
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	read();
	getans();
}
