/*
LANG: C++
PROG: telecow
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 210, maxm = 12010, cs = 1073741823;
class Poi
{
	public:
	int x, y;
} edge[maxm];
int g1[maxn], s[maxm], next[maxm], f[maxm];
int an[maxm], dis[maxn], vh[maxn];
bool can[maxn];
int N, M, begin, end, S, T, total;

void read()
{
	scanf("%d%d%d%d", & N, & M, & begin, & end);
	for (int i = 1; i <= M; ++i)
		scanf("%d%d", & edge[i].x , & edge[i].y);
}

void init(int i, int j, int l)
{
	int i1 = i, j1 = j;
	if (i1 > N) i1 -= N;
	if (j1 > N) j1 -= N;
	if (!can[i1] || (!can[j1])) return; 
	s[++total] = j ; next[total] = g1[i]; g1[i] = total; f[total] = l;
	s[++total] = i; next[total] = g1[j]; g1[j] = total; f[total] = 0;
}

void construct()
{
	memset(g1, 0, sizeof g1);
	total = 1;
	for (int i = 1; i <= N; ++i) if ((i != begin) && (i != end))
		init(i, i + N, 1);
	init(begin, begin + N, cs), init(end, end + N, cs);
	for (int i = 1; i <= M; ++i) 
		init(edge[i].x + N, edge[i].y, cs),
		init(edge[i].y + N, edge[i].x, cs);
}

void prepare()
{
	memset(vh, 0, sizeof vh);
	memset(dis, 0, sizeof dis);
	vh[0] = 2 * N;
	S = begin, T = N + end;
}

int flow(int v,int total)
{
//	cerr << v << ' ' << total << endl;
	if (v == T) return total;
	int Min = N * 2 + 1, l = total;
	for (int temp = g1[v]; temp; temp = next[temp]) if (f[temp])
	{
		if (dis[s[temp]] == dis[v] - 1)
		{
			int d1 = flow(s[temp], min(l, f[temp]));
			f[temp] -= d1, f[temp ^ 1] += d1;
			l -= d1;
			if (dis[1] >=2 * N) return total - l;
			if (!l) break;
		}
		Min = min(Min, dis[s[temp]] + 1);
	}
	if (total == l)
	{
		if (!(--vh[dis[v]])) dis[1] = 2 * N + 1;
		++vh[dis[v] = Min];
	}
	return total - l;
}

int MaxFlow()
{
	construct();
	prepare();
	
	int ans = 0;
	while (dis[1] < N * 2)
	{
		 ans += flow(S, 1073741824);
		// cerr << ans << endl;
	//cerr << endl << endl  << endl << endl << endl << endl;
	}
	return ans;
}

void getans()
{
	memset(can ,true, sizeof can);
	int ans = MaxFlow();
	cout << ans << endl;
	
	int tot = 0;
	for (int i = 1; i <= N; ++i) if ((i != begin) &&( i != end))
	{
		can[i] = false;
		int temp = MaxFlow();
		if (temp < ans)	
		{
			//cerr << i << " : " << ans << ' ' << temp << endl;
			an[++tot] = i, ans = temp;
		}
		else can[i] = true;
	}
	
	for (int i = 1; i < tot; ++i) cout << an[i] << ' ';
	if (tot) cout << an[tot] << endl;
}

int main()
{
	freopen("telecow.in", "r", stdin);
	freopen("telecow.out", "w", stdout);
	read();
	getans();
}
