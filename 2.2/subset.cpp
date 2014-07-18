/*
LANG: C++
PROG: subset
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2010;
long long f[maxn];
int N;

void read()
{
	scanf("%d", & N);
}

void getans()
{
	int sum = (1 + N) * N / 2;
	if (sum & 1)
	{
		cout << 0 << endl;
		return;
	}
	
	memset(f, 0, sizeof f);
	f[0] = 1;
	sum >>= 1;
	
	for (int i = 1; i <= N; ++i)
		for (int j = sum; j >= i; --j) f[j] += f[j - i];
	cout << f[sum] / 2 << endl;
}

int main()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	read();
	getans();
}
