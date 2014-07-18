/*
LANG: C++
PROG: milk6
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 34, maxm = 2010;
int s[maxm], next[maxm], g1[maxn];
long long f[maxm];
int dis[maxn], vh[maxn];
int N, M, total;
bool can[maxm], man[maxm];
int an[maxm];

void init(int i, int j , int k)
{
	s[++total] = j; next[total] = g1[i]; g1[i] = total; f[total] = k * (long long)(M + 1) + 1;
	s[++total] = i; next[total] = g1[j]; g1[j] = total; f[total] = 0;
}

void read()
{
	scanf("%d%d", & N, & M);
	total = 1;
	for (int i = 1; i <= M; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", & a, & b, & c);
		init(a, b, c);
	}
}

void back()
{
	for (int i = 2; i <= total; i += 2)
	{
		f[i] = f[i] + f[i ^ 1];
		f[i ^ 1] = 0;
	}
	memset(dis, 0, sizeof dis);
	memset(vh, 0, sizeof vh);
	vh[0] = N;
}

long long get(int v, long long total)
{
	//cerr << v << ' ' << total << endl;
	if ((v == N) || (!total)) return total;
	int Min = N;
	long long l = total;
	for (int temp = g1[v]; temp; temp = next[temp]) if (f[temp] && can[temp])
	{
		if (dis[s[temp]] == dis[v] - 1)
		{
			long long d1 = get(s[temp], min(f[temp], l));
			f[temp] -= d1, f[temp ^ 1] += d1;
			l -= d1;
			if (dis[1] >= N) return total - l;
			if (!l) break;
		}
		Min = min(Min, dis[s[temp]] + 1);
	}
	if (total == l)
	{
		if (!(--vh[dis[v]])) dis[1] = N + 1;
		++vh[dis[v] = Min];
	}
	return total - l;
}

long long flow()
{
	back();
	long long ans = 0;
	while (dis[1] < N)
		ans += get(1, 2073741824000000LL);
	return ans;
}

void getans()
{
	memset(can, true, sizeof can);
	long long sum = flow();
	cout << sum / (M + 1) << ' ' << sum % (M + 1) << endl;
	
	memset(man, false, sizeof man);
	for (int i = 1; i <= M; ++i) if (!f[2 * i]) man[i] = true;
	
	int ans = 0;
	for (int i = 1; i <= M; ++i) if (man[i])
	{
		can[2 * i] = can[2 * i + 1] = false;
		long long temp = flow();
		if (temp + f[2 * i] + f[2 * i + 1] == sum)
		{
			an[++ans] = i;
			sum = temp;
			if (sum == 0) break;
		}
		else can[2 * i] = can[2 * i + 1] = true;
	}
	
	for (int i = 1; i <= ans; ++i) cout << an[i] << endl;
}

int main()
{
	freopen("milk6.in", "r", stdin);
	freopen("milk6.out", "w", stdout);
	read();
	getans();
}
