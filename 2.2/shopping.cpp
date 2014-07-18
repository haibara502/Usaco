#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 12, maxm = 1010;
bool show[maxm];
int sum[maxn], price[maxn];
class Poi
{
	public:
	int x, y;
	Poi(int x = 0, int y = 0):x(x), y(y){}
} yh[maxn][maxn];
int f[6][6][6][6][6];
int N, M, total;

int Int(int v)
{
	if (show[v]) return show[v];
	return show[v] = ++total;
}

void read()
{
	scanf("%d", & M);
	memset(show, 0, sizeof show);
	total = 0;
	for (int i = 1; i <= M; ++i)
	{
		scanf("%d", & sum[i]);
		for (int j = 1; j <= sum[i]; ++j)
		{
			int a, b;
			scanf("%d%d", & a, & b);
			a = Int(a);
			yh[i][j] = Poi(a, b);
		}
		scanf("%d", & price[i]);
	}
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", & a, & b, & c);
		a = Int(a);
		buy[i] = a;
		need[a] = b;
		sum[++M] = 1;
		yh[M][1] = Poi(a, 1);
		price[M] = c;
	}
}

int dfs(int need[6])
{
	if (f[need[1]][need[2]][need[3]][need[4]][need[5]] != -1)
		return f[need[1]][need[2]][need[3]][need[4]][need[5]];
	int ans = -1;
	for (int e = 1; e <= M; ++e)
	{
		for (int i = 1; i < 6; ++i) temp[i] = need[i];
		bool ff = true;
		for (int o = 1; o <= sum[e]; ++o) 
		{
			bool ff1 = false;
			for (int r = 1; r <= 5; ++r) if (buy[r] == yh[e][o].x)
			{
				temp[r] -= yh[e][o].y;
				ff1 = true; 
				break;
			}
			if (!ff1) 
			{
				ff = false; break;
			}
		}
		if (!ff) continue;
		ans = min((unsigned)ans, (unsigned)(dfs(temp)) + price[e]);
	}
	return f[need[1]][need[2]][need[3]][need[4]][need[5]] = ans;
}

void getans()
{
	memset(f, -1, sizeof f);
	f[0][0][0][0][0] = 0;
	cout << dfs(need) << endl;
}

int main()
{
	read();
	getans();
}
