/*
LANG: C++
PROG: zerosum
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10;
int N, now;
char an[maxn];

void read()
{
	scanf("%d", & N);
}

void print()
{
	for (int i = 1; i < N; ++i) cout << i << an[i + 1];
	cout << N << endl;
}

void dfs(int pre, int deep, int need)
{
	//cerr << pre << ' ' << deep << ' ' << need << endl;
	if (deep > need)
	{
		now = now + pre;
		if (now == 0) print();
		now -= pre;
		return;
	}
	an[deep] = ' ';
	if (pre < 0) pre = pre * 10 - deep;
	else pre = pre * 10 + deep;
	dfs(pre, deep + 1, need);
	pre /= 10;
	now += pre;
	an[deep] = '+';
	dfs(deep, deep + 1, need);
	an[deep] = '-';
	dfs(-deep, deep + 1, need);
	now -= pre;
}

void getans()
{
	now = 0;
	dfs(1, 2, N);
}

int main()
{
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	read();
	getans();
}
