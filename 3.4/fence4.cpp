/*
LANG: C++
PROG: fence4
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 210;
const double pi = acos(-1);
class Poi
{
	public:
	int x, y;
	Poi(int x = 0, int y = 0):x(x), y(y){}
	bool operator <(const Poi & Q) const
	{
		if (y != Q.y) return y < Q.y;
		return x < Q.x;
	}
} pos[maxn], an[maxn];
double jj[maxn], can[maxn];
int belong[maxn];
int N, X, Y;

void read()
{
	scanf("%d", & N);
	scanf("%d%d", & X, & Y);
	for (int i = 1; i <= N; ++i) 
	{
		scanf("%d%d", & pos[i].x, & pos[i].y);
		pos[i].x -= X, pos[i].y -= Y;
	}
}

void print(const Poi & Q) 
{
	cout << Q.x + X << ' ' << Q.y + Y;
}

int cha(int l1, int r1, int l2, int r2)
{
	int x = l1 * r2 - l2 * r1;
	if (x < 0) return -1;
	return (x > 0);
}

int check(Poi l1, Poi r1, Poi l2, Poi r2, int o)
{
//	cerr << "check :" << endl;
//	print(l1), print(r1), print(l2), print(r2);
	int x = cha(l1.x - r1.x, l1.y - r1.y, l2.x - r1.x, l2.y - r1.y);
	int y = cha(l1.x - r1.x, l1.y - r1.y, r2.x - r1.x, r2.y - r1.y);
//	cerr << x << ' ' << y << endl;
//	cerr << "check ends" << endl;
	return x * y;
}

bool pan(Poi l1, Poi r1, Poi z, Poi l2, Poi r2)
{
//	cerr << "pan: " << endl;
//	print(l2), print(r2);
//	cerr << check(l1, r1, z, l2, 1) << ' ' << check(l1, r1, z, r2, 1) << endl;
	return ((check(l1, r1, z, l2, 1) < 0) || (check(l1, r1, z, r2, 1) < 0));
}

bool jiao(Poi l1, Poi r1, Poi l2, Poi r2)
{
	int x = check(l1, r1, l2, r2, 0);
	if (x >= 0) return false;
	x = check(l2, r2, l1, r1, 0);
	return x < 0;
}

void update(int i, double l, double r, int total)
{
//	cerr << i << ' ' << l << ' ' << r << ' ' << total << endl;
	int left = lower_bound(jj + 1, jj + 1 + total, l) - jj, right = lower_bound(jj + 1, jj + 1 + total, r) - jj;
//	cerr << left << ' ' << right << endl;
	for (int j = left; j < right; ++j)
	{
		if (belong[j] == 0) belong[j] = i;
		else 
		{
	//		cerr << belong[j] << endl;
			if (pan(pos[i], pos[i + 1], Poi(0, 0), pos[belong[j]], pos[belong[j] + 1]))
				belong[j] = i;
		//	cerr << pan(pos[i], pos[i + 1], Poi(0, 0), pos[belong[j]], pos[belong[j] + 1]) << endl;
		}
//		cerr << pan(pos[i], pos[i + 1], Poi(0, 0), pos[belong[j]], pos[belong[j] + 1]) << endl;
		//cerr << "j : " << j << ' ' << belong[j] << endl;
	}
}

void getans()
{
	pos[N + 1] = pos[1];
	for (int i = 1; i < N; ++i)
		for (int j = i + 1; j <= N; ++j) 
			if (jiao(pos[i], pos[i + 1], pos[j], pos[j + 1]))
			{
				print(pos[i]), print(pos[i + 1]), print(pos[j]), print(pos[j + 1]);
				cout << "NOFENCE" << endl;
				return;
			}
			
	for (int i = 1; i <= N; ++i)
		jj[i] = atan2(pos[i].y, pos[i].x);
	jj[N + 1] = -pi, jj[N + 2] = pi;
	sort(jj + 1, jj + N + 2 + 1);
	int total = unique(jj + 1, jj + N + 2 + 1) - jj - 1;
//	for (int i = 1; i <= total; ++i) cerr << jj[i] << ' ';
//	cerr << endl;
//	cerr << total << endl;
	for (int i = 1; i < total; ++i) belong[i] = 0;
	
	
	for (int i = 1; i <= N; ++i)
	{
//		cerr << "I: " << i << endl;
		double l = atan2(pos[i].y, pos[i].x), r = atan2(pos[i + 1].y, pos[i + 1].x);
//		cerr << l << ' ' << r << endl;
		if ((l == pi) && (r < 0)) l = -pi;
		if ((r == pi) && (l < 0)) r = -pi;
		if ((l > 0) && (r < 0))
		{
			update(i, l, pi, total);
			update(i, -pi, r, total);
			continue;
		}
		if (l > r) swap(l, r);
	//	cerr << l << ' ' << r << endl;
		update(i, l, r, total);
	}
	
	memset(can, false, sizeof can);
	for (int i = 1; i < total; ++i) can[belong[i]] = true;
	//cerr << "---" << endl;
	//for (int i = 1; i < total; ++i) cerr << belong[i] << endl;
	
	int ans = 0;
	for (int i = 1; i < N; ++i) if (can[i])
		an[++ans] = Poi(i, i + 1);
	if (can[N]) an[++ans] = Poi(1, N);
	cout << ans << endl;
	sort(an + 1, an + 1 + ans);
	for (int i = 1; i <= ans; ++i) 
	{
		print(pos[an[i].x]);
		cout << ' ';
		print(pos[an[i].y]);
		cout << endl;
	}
}

int main()
{
	freopen("fence4.in", "r", stdin);
	freopen("fence4.out", "w", stdout);
	read();
	getans();
}
