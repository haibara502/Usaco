/*
LANG: C++
PROG: packrec
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 10;
int a[maxn][2], way[maxn][2];
bool p[maxn];
int ans, sum;
class Poi
{
	public:
		int x, y;
		Poi(int x = 0, int y = 0) :x(x), y(y){}
		bool operator <(const Poi & Q) const
		{
			if (x != Q.x) return x < Q.x;
			return y < Q.y;
		}
		bool operator ==(const Poi & Q) const
		{
			return ((x == Q.x) && (y == Q.y));
		}
};
vector<Poi> an;

void read()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 2; ++j) scanf("%d", & a[i][j]);
}

void update(int x, int y)
{
	if (ans < x * y) return;
	else if (ans > x * y)
		ans = x * y, an.clear();
	if (x > y) swap(x, y);
	an.push_back(Poi(x, y));
}

void calc()
{
	int cntx = 0, cnty = 0;
	
//	case 1:
	for (int i = 0; i < 4; ++i) cntx += way[i][0], cnty = max(cnty, way[i][1]);
	update(cntx, cnty);
	
//	case 2:
	cntx = 0, cnty = 0;
	for (int i = 0; i < 3; ++i) cntx += way[i][0], cnty = max(cnty, way[i][1]);
	cntx = max(cntx, way[3][0]), cnty += way[3][1];
	update(cntx, cnty);
		
//	case 3:
	cntx = way[0][0] + way[1][0];
	cnty = max(way[0][1], way[1][1]);
	cntx = max(cntx, way[2][0]);
	cnty += way[2][1];
	cntx += way[3][0];
	cnty = max(cnty, way[3][1]);
	update(cntx, cnty);
	
//	case 4:
	cntx = way[0][0] + way[3][0] + max(way[1][0], way[2][0]);
	cnty = max(way[0][1], max(way[3][1], way[2][1] + way[1][1]));
	update(cntx, cnty);
	
//	case 5:
	cnty = max(way[0][1] + way[1][1], way[2][1] + way[3][1]);
	if (way[1][1] >= way[2][1])
		if (way[1][1] >= way[2][1] + way[3][1])
			cntx = max(way[0][0], way[1][0] + max(way[2][0], way[3][0]));
		else
			cntx = max(way[1][0] + way[2][0], max(way[1][0], way[0][0]) + way[3][0]);
	else
		cntx = max(max(way[0][0], way[1][0]) + way[2][0], way[0][0] + way[3][0]);
	update(cntx, cnty);
}

void dfs(int deep, int need)
{
	if (deep == need) calc();
	for (int i = 0; i < 4; ++i) if (!p[i])
	{
		p[i] = true;
		for (int j = 0; j < 2; ++j) way[deep][j] = a[i][j];
		dfs(deep + 1, need);
		swap(way[deep][0], way[deep][1]);
		dfs(deep + 1, need);
		p[i] = false;
	}
}

void getans()
{
	memset(p, false, sizeof p);
	ans = 1073741824, sum = 0;
	dfs(0, 4);
	cout << ans << endl;
	sort(an.begin(), an.end());
	vector<Poi>::iterator end = unique(an.begin(), an.end());
	for (vector<Poi>::iterator it = an.begin(); it < end; ++it)
		cout << (*it).x << ' ' << (*it).y << endl;
}

int main()
{
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);
	read();
	getans();
}
