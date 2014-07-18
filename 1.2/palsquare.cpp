/*
ID: haibara3
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int d[maxn];
int base;

void read()
{
	scanf("%d", & base);
}

bool zhuan(int v)
{
	int len = 0;
	for (; v; v /= base)
		d[++len] = v % base;
	for (int i = 1; len - i + 1 >= i; ++i)
		if (d[i] != d[len - i + 1]) return false;
	return true;
}

void print(int v)
{
	int len = 0;
	for (; v; v /= base)
		d[++len] = v % base;
	for (int i = len; i; --i) 
		if (d[i] < 10) cout << d[i];
		else cout << char(d[i] - 10 + 'A');
}

void getans()
{
	for (int i = 1; i <= 300; ++i) if (zhuan(i * i))
	{
		print(i);
		cout << ' ';
		print(i * i);
		cout << endl;
	}
}

int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	read();
	getans();
}
