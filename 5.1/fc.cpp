/*
LANG: C++
PROG: fc
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int maxn = 10010;
class Poi
{
	public:
	double x, y;
	bool operator <(const Poi & Q) const
	{
		if (y != Q.y) return y > Q.y;
		return x < Q.x;
	}
} a[maxn], d[maxn * 2];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
		cin >> a[i].x >> a[i].y;
}

double cha(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

bool check(Poi a, Poi b, Poi c)
{
	return cha(a.x - b.x, a.y - b.y, b.x - c.x, b.y - c.y) >= 0;
}

double sqr(double x)
{
	return x * x;
}

void getans()
{
	sort(a + 1, a + 1 + N);
	
	int open = 0;
	for (int i = 1; i <= N; ++i)
	{
		while ((open > 1) && (check(d[open - 1], d[open], a[i]))) --open;
		d[++open] = a[i];
	}
	
	int limit = open;
	for (int i = N; i; --i)
	{
		while ((open > limit) && (check(d[open - 1], d[open], a[i]))) --open;
		d[++open] = a[i];
	}
	
	double ans = 0;
	for (int i = 2; i <= open; ++i) ans += sqrt(sqr(d[i].x - d[i - 1].x) + sqr(d[i].y - d[i - 1].y));
	cout << fixed << setprecision(2) << ans << endl;
//	for (int i = 1; i <= open; ++i) cerr << d[i].x << ' ' << d[i].y << endl;	
}

int main()
{
	freopen("fc.in", "r", stdin);
	freopen("fc.out", "w", stdout);
	read();
	getans();
}
