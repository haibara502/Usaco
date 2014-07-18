/*
LANG: C++
PROG: fence3
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

const int maxn = 210;
class Poi
{
	public:
	double x, y;
	Poi(double x = 0, double y = 0):x(x), y(y){}
	bool operator <(const Poi & Q) const
	{
		if (x != Q.x) return x < Q.x;
		return y < Q.y;
	}
} a[maxn], b[maxn], c[maxn];
double dis[maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%lf%lf%lf%lf", & a[i].x, & a[i].y, & b[i].x, & b[i].y);
}

double cha(double x1, double y1, double x2, double y2)
{
	return abs(x1 * y2 - x2 * y1);
}

double sqr(double x)
{
	return x * x;
}

double dist(Poi a, Poi b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

bool inside(double x, double y, Poi a, Poi b)
{
	if (dist(a, b) < 1e-8) return false;
	if (b < a) swap(a, b);
//	cerr << a.x << ' ' << b.x << ' ' << a.y << ' ' << b.y << ' ' << x << ' ' << y << endl;
	if (a.x != b.x)
		return (a.x <= x) && (x <= b.x);
	if (a.y != b.y)
		return (a.y <= y) && (y <= b.y);
}

double calc(double x, double y)
{
	//cerr << x << ':' << y << endl;
	double ans = 0;
	for (int i = 1; i <= N; ++i) 
	{
		//cerr << "i : " << i << endl;
		if (inside(x, y, a[i], b[i]))
		{
			//cerr << "inside" << endl;
			double temp = cha(a[i].x - b[i].x, a[i].y - b[i].y, x - b[i].x, y - b[i].y) / dist(a[i], b[i]);
			//cerr << temp << endl;
			ans += temp;
		}
		else ans += min(dist(Poi(x, y), a[i]), dist(Poi(x, y), b[i]));
	}
	return ans;
}

void getans()
{
	for (int i = 1; i <= 100; ++i)
	{
		c[i] = Poi(rand() % 100, rand() % 100);
		dis[i] = calc(c[i].x, c[i].y);
	}
	
	for (double T = 100; T >= 0.01; T *= 0.8)
		for (int i = 1; i <= 100; ++i)
		{
			double jiaodu = rand();
			double x = T * cos(jiaodu);
			double y = T * sin(jiaodu);
			double temp = calc(x + c[i].x, y + c[i].y);
			if (temp < dis[i])
				c[i] = Poi(x + c[i].x, y + c[i].y), dis[i] = temp;
		}
		
	int temp1 = 1;
	for (int i = 2; i <= 100; ++i) if (dis[i] < dis[temp1])
		temp1 = i;
	cout << fixed << setprecision(1) << c[temp1].x << ' ' << c[temp1].y << ' ' << dis[temp1] << endl;	
}

int main()
{
	freopen("fence3.in", "r", stdin);
	freopen("fence3.out", "w", stdout);
	read();
	getans();
}
