/*
PROG: picture
ID: haibara3
LANG: C++
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
	int x1, y1, x2, y2;
	void read()
	{
		scanf("%d%d%d%d", & x1, & y1, & x2, & y2);
		x1 += 10000, y1 += 10000, x2 += 10000, y2 += 10000;
	}
} rec[maxn];
class Seg
{
	public:
	int x1, x2, y, tag;
	bool operator <(const Seg & Q) const
	{
		if (y != Q.y) return y < Q.y;
		return tag > Q.tag;
	}
	Seg(int x1 = 0, int x2 = 0, int y = 0, int tag = 0):x1(x1), x2(x2), y(y), tag(tag){};
} seg[2 * maxn];
int N, ans;
int re[4 * maxn], hash[4 * maxn];
int color[20010];

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) rec[i].read();
}

void solve()
{
	for (int i = 1; i <= 2 * N; ++i) 
		hash[2 * i - 1] = seg[i].x1, 
		hash[2 * i] = seg[i].x2;
	sort(hash + 1, hash + 1 + 4 * N);
	int total = unique(hash + 1, hash + 1 + 4 * N) - hash;

	for (int i = 1; i <= 2 * N; ++i)
	{
		int t = lower_bound(hash + 1, hash + 1 + total, seg[i].x1) - hash;
		re[t] = seg[i].x1;
		seg[i].x1 = t;
		t = lower_bound(hash + 1, hash + 1 + total, seg[i].x2) - hash;
		re[t] = seg[i].x2;
		seg[i].x2 = t;
	}
		
	sort(seg + 1, seg + 1 + 2 * N);
	memset(color, 0, sizeof color);
	for (int i = 1; i <= 2 * N; ++i)
		for (int j = seg[i].x1; j < seg[i].x2; ++j) 
		{
			if (!color[j]) ans += re[j + 1] - re[j];
			color[j] += seg[i].tag;
			if (!color[j]) ans += re[j + 1] - re[j];	
		}
}

void getans()
{
	ans = 0;
	
	for (int i = 1; i <= N; ++i)
		seg[2 * i - 1] = Seg(rec[i].x1, rec[i].x2, rec[i].y1, 1),
		seg[2 * i] = Seg(rec[i].x1, rec[i].x2, rec[i].y2, -1);
	solve();
	
	for (int i = 1; i <= N; ++i)
		seg[2 * i - 1] = Seg(rec[i].y1, rec[i].y2, rec[i].x1, 1),
		seg[2 * i] = Seg(rec[i].y1, rec[i].y2, rec[i].x2, -1);
	solve();
	
	cout << ans << endl;
}

int main()
{
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	read();
	getans();
}
