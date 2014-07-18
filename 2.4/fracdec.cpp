/*
LANG: C++
PROG: fracdec
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int p[maxn], ans[maxn];
int N, D;
string an;

void read()
{
	scanf("%d%d", & N, & D);
}

void append(int v)
{
	if (!v)
	{
		an += '0';
		return;
	}
	string temp("");
	for (; v; v /= 10)
		temp = char(v % 10 + '0') + temp;
	an += temp;
}

void getans()
{	
	memset(p, 0, sizeof p);
	append(N / D);
	an += '.';
	N %= D; int M = N;
	++p[N];
	for (int i = 1;; ++i)
	{
		ans[i] = (N * 10) / D;
		N = ((N * 10) % D); 
		if (N == 0) break;
		if (++p[N] == 2) break;
	}
	
	int cnt = 0;
	bool ct = false;
	bool ff = false;
	for (int i = 1;; ++i)
	{
		if (--p[M] == 1) 
			an = an + '(', --p[M], ff = true;
		M = (M * 10) % D;
		if (M || ans[i]) ct = true, append(ans[i]);
		if (p[M] == 0)
			break;
	}
	if (!ct) append(0);
	if (ff) an = an + ')';
	
	for (int i = 0; i < an.size(); ++i)
	{
		cout << an[i];
		if (i % 76 == 75) cout << endl;
	}
	cout << endl;
}

int main()
{
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	read();
	getans();
}
