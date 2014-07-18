/*
LANG: C++
PROG: nuggets
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 11;
int a[maxn], f[257 * 257];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

void getans()
{
	bool ff = false;
	for (int i = 1; i <= N; ++i) if (a[i] == 1) ff = true;
	if ((ff) || (N == 1)) 
	{
		cout << 0 << endl;
		return;
	}
	
	int Gcd = a[1];
	for (int i = 2; i <= N; ++i) Gcd = gcd(Gcd, a[i]);
	if (Gcd != 1) 
	{
		cout << 0 << endl;
		return;
	}
	
	sort(a + 1, a + 1 + N);
	int maxM = a[N - 1] * a[N] / gcd(a[N - 1], a[N]);
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = a[i]; j <= maxM; ++j)
			f[j] += f[j - a[i]];
	for (int i = maxM; i; --i) if (!f[i])
	{
		cout << i << endl;
		return;
	}
	cout << 0 << endl;
}

int main()
{
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);
	read();
	getans();
}
