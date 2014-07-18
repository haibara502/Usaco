/*
LANG: C++
PROG: cowcycle
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int F[maxn], R[maxn], anF[maxn], anR[maxn];
double d[maxn * maxn];
int N, M, F1, F2, R1, R2;
double ans;
void read()
{
	scanf("%d%d", & N, & M);
	scanf("%d%d%d%d", & F1, & F2, & R1, & R2);
}

double sqr(double v)
{
	return v * v;
}

void calc()
{
	if (F[N] * R[M] < 3 * F[1] * R[1]) return;
	int open = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			d[++open] = F[i] * 1.0 / R[j];
	sort(d + 1, d + 1 + open);
	double mean = 0;
	for (int i = 2; i <= open; ++i) mean += d[i] - d[i - 1];
	mean /= (open - 1);
	double variance = 0;
	for (int i = 2; i <= open; ++i) 
		variance += sqr(d[i] - d[i - 1] - mean);
	variance /= (1.0 * N * M - 1);
	if (variance < ans)
	{
		ans = variance;
		for (int i = 1; i <= N; ++i) anF[i] = F[i];
		for (int i = 1; i <= M; ++i) anR[i] = R[i];
	}
}

void dfsR(int deep, int l)
{
	if (deep > M)
	{
		calc();
		return;
	}
	for (int i = l; i <= R2 - (M - deep); ++i)
	{
		R[deep] = i;
		dfsR(deep + 1, i + 1);
	}
}

void dfsF(int deep, int l)
{
	if (deep > N)
	{
		dfsR(1, R1);
		return;
	}
	for (int i = l; i <= (F2 - (N - deep)); ++i)
	{
		F[deep] = i;
		dfsF(deep + 1, i + 1);
	}
}

void getans()
{
	ans = 1e50;
	dfsF(1, F1);
	for (int i = 1; i < N; ++i) cout << anF[i] << ' ';
	cout << anF[N] << endl;
	for (int i = 1; i < M; ++i) cout << anR[i] << ' ';
	cout << anR[M] << endl;
}

int main()
{
	freopen("cowcycle.in", "r", stdin);
	freopen("cowcycle.out", "w", stdout);
	read();
	getans();
}
