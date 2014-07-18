/*
LANG: C++
PROG: wissqu
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20, x[9][2] = {0, 0, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
class Poi
{
	public:
	char w;
	int x, y;
	Poi(char w = ' ', int x = 0, int y = 0):w(w), x(x), y(y) {}
	void print()
	{
		cout << w << ' ' << x + 1 << ' ' << y + 1 << endl;
	}
} way[maxn];
char a[maxn][maxn], sum[256];
int ans;
bool p[maxn][maxn];

void read()
{
	for (int i = 0; i < 4; ++i) scanf("%s", a[i]);
}

bool can(int j, int k, char i)
{
	for (int e = 0; e < 9; ++e)
	{
		int j1 = j + x[e][0], k1 = k + x[e][1];
		if ((j1 < 0) || (k1 < 0) || (j1 >= 4) || (k1 >= 4)) continue;
		if (a[j1][k1] == i) return false;
	}
	return true;
}

void dfs(int deep)
{
	if (deep > 16)
	{
		++ans;
		if (ans == 1)
			for (int i = 1; i <= 16; ++i) way[i].print();
		return;
	}
//	cerr << deep << endl;
	for (int i = 'A'; i <= 'E'; ++i) if (sum[i])
		for (int j = 0; j < 4; ++j) 
			for (int k = 0; k < 4; ++k) if (!p[j][k] && can(j, k, i))
			{
				--sum[i];
				p[j][k] = true;
				char w = a[j][k];
				a[j][k] = i;
				if (!ans) way[deep] = Poi(i, j, k);
				dfs(deep + 1);
				p[j][k] = false;
				a[j][k] = w;
				++sum[i];
			}
}

void getans()
{
	sum['A'] = sum['B'] = sum['C'] = 3;
	sum['D'] = 4; sum['E'] = 3;
	ans = 0;
	dfs(1);
	cout << ans << endl;
}

int main()
{
	freopen("wissqu.in", "r", stdin);
	freopen("wissqu.out", "w", stdout);
	read();
	getans();
}
