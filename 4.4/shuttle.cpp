/*
LANG: C++
PROG: shuttle
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 30;
int d[maxn];
long long queue[500100];
int pre[500100], way[500100];
long long begin, end;
int N, ans;
int an[500100];

void read()
{
	scanf("%d", & N);
}

long long calc()
{
	long long sum = 0;
	for (int i = 2 * N + 1; i; --i) sum = sum * 3 + d[i];
	return sum;
}

void update(long long v, int closed, int &open, int chosen)
{
	queue[++open] = v;
	pre[open] = closed, way[open] = chosen;
	
	if (v == end)
	{
		ans = 0;
		for (int i = open; i != 1; i = pre[i])
			an[++ans] = way[i];
		for (int i = 1; i <= ans; ++i) 
		{
			cout << an[ans - i + 1] ;
			if ((i % 20) && (i != ans)) cout << ' ';
			else cout << endl;
		}
		exit(0);
	}
}

void getans()
{
	for (int i = 1; i <= N; ++i) d[i] = 1;
	for (int i = N + 2; i <= 2 * N + 1; ++i) d[i] = 2;
	begin = calc();
	for (int i = 1; i <= N; ++i) d[i] = 2;
	for (int i = N + 2; i <= 2 * N + 1; ++i) d[i] = 1;
	end = calc();
	
	queue[1] = begin;
	int closed = 0, open = 1;
	while (closed < open)
	{
		long long t = queue[++closed];
		//cerr << "closed : " << closed << endl;
		memset(d, 0, sizeof d);
		int len = 0;
		for (; t; t /= 3) d[++len] = t % 3;
		//for (int i = 1; i <= 2 * N + 1; ++i) cerr << d[i] << ' ';
		//cerr << endl;
		int zero = 1;
		for (; d[zero] != 0; ++zero);
		//cerr << zero << endl;
		//cerr << pre[closed] << ' ' << way[closed] << endl;
		if ((zero >= 3) && (d[zero - 1] + d[zero - 2] == 3) && (d[zero - 2] == 1))
		{
			swap(d[zero], d[zero - 2]);
			long long d1 = calc();
			swap(d[zero], d[zero - 2]);
			update(d1, closed, open, zero - 2);
		}
		if ((zero > 1) && (d[zero - 1] == 1))
		{
			swap(d[zero], d[zero - 1]);
			long long d1 = calc();
			swap(d[zero], d[zero - 1]);
			update(d1, closed, open, zero - 1);
		}
		if ((zero < 2 * N + 1) && (d[zero + 1] == 2))
		{
			swap(d[zero], d[zero + 1]);
			long long d1 = calc();
			swap(d[zero], d[zero + 1]);
			update(d1, closed, open, zero + 1);
		}
		if ((zero < 2 * N) && (d[zero + 1] + d[zero + 2] == 3) && (d[zero + 2] == 2))
		{
			swap(d[zero], d[zero + 2]);
			long long d1 = calc();
			swap(d[zero], d[zero + 2]);
			update(d1, closed, open, zero + 2);
		}
	}
}

int main()
{
	freopen("shuttle.in", "r", stdin);
	freopen("shuttle.out", "w",stdout);
	read();
	getans();
}
