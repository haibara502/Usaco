/*
ID: haibara3
LANG: C++
PROG: ariprog
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000100;
class Poi
{
	public:
		int x, y;
		bool operator <(const Poi & Q) const
		{
			if (y != Q.y) return y < Q.y;
			return x < Q.x;
		}
		Poi(int x = 0, int y = 0):x(x), y(y){};
} an[maxn];
int d[maxn];
bool show[maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
}

void getans()
{
	int total = 0;
	memset(show, false, sizeof show);
	for (int i = 0; i <= M; ++i)
		for (int j = i; j <= M; ++j) 
		{
			d[++total] = i * i + j * j;
			show[d[total]] = true;
		}
	sort(d + 1, d + 1 + total);
	int temp = 1;
	for (int i = 2; i <= total; ++i) if (d[i] != d[i - 1]) d[++temp] = d[i];
	total = temp; 
	
	int ans = 0;
	for (int i = 1; i <= total; ++i)
		for (int j = i + 1; j <= total; ++j)
		{
			bool ff = true;
			int a = d[i], b = d[j] - d[i];
			if (a + (N - 1) * b > d[total]) break;
			for (int k = 2; k < N; ++k)
				if (!show[a + b * k]) ff = false;
			if (ff) 
				an[++ans] = Poi(a, b);
		}
	if (ans == 0)
	{
		cout << "NONE" << endl;
		return;
	}
	sort(an + 1, an + 1 + ans);
	for (int i = 1; i <= ans; ++i) cout << an[i].x << ' ' << an[i].y << endl;
}

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	read();
	getans();
}
