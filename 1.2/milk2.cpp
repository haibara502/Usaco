/*
LANG: C++
PROG: milk2
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5010;
class Poi
{
	public:
	int x, y;
	bool operator <(const Poi & Q) const
	{
		if (x != Q.x) return x < Q.x;
		return y > Q.y;
	}
	Poi(int x = 0, int y = 0):x(x), y(y) {}
} tme[2 * maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
	{
		int a, b;
		scanf("%d%d", & a, & b);
		tme[2 * i - 1] = Poi(a, 1);
		tme[2 * i] = Poi(b, -1);
	}
}

void getans()
{
	sort(tme + 1, tme + 1 + 2 * N);
	int point = tme[1].x, people = 1;
	int ansy = 0, ansmy = 0;
	for (int i = 2; i <= 2 * N; ++i)
	{
		//cerr << point << ' ' << people << ' ' << tme[i].x << ' ' << tme[i].y << endl;
		if (people == 0)
			ansmy = max(ansmy, tme[i].x - point), 
			point = tme[i].x;
		else if (people + tme[i].y == 0)
			ansy = max(ansy, tme[i].x - point),
			point = tme[i].x;
		people += tme[i].y;
	}
	cout << ansy << ' ' << ansmy << endl;
}

int main()
{
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	read();
	getans();
}
