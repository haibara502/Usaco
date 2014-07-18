/*
ID: haibara3
PROG: buylow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5010, maxl = 100;
int a[maxn], f[maxn], nex[maxn];
int N;
class Poi
{
	int l, a[maxl];
	void jin()
	{
		for (int i = 1; i <= l; ++i) 
			a[i + 1] += a[i] / 10, a[i] %= 10;
		if (a[l + 1]) ++l;
	}
	public:
	Poi():l(1)
	{
		memset(a, 0, sizeof a);
	}
	void operator +=(const Poi & Q)
	{
		l = max(l, Q.l);
		for (int i = 1; i <= l; ++i) a[i] += Q.a[i];
		jin();
	}
	Poi operator =(const int & Q)
	{
		a[1] = Q;
		l = 1;
		return *this;
	}
	void print()
	{
		for (int i = l; i; --i) cout << a[i];
		cout << endl;
	}
} g[maxn];
	
void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

void getans()
{
	a[++N] = -1;

	for (int i = 1; i <= N; ++i)
	{
		nex[i] = N + 1;
		for (int j = i + 1; j <= N; ++j) if (a[j] == a[i])
		{
			nex[i] = j; break;
		}
	}
	
	for (int i = 1; i <= N; ++i)
	{
		f[i] = 1;
		for (int j = 1; j < i; ++j) if ((a[j] > a[i]) && (f[j] >= f[i])) 
			f[i] = max(f[i], f[j] + 1) ;
			
		if (f[i] != 1)
			for (int j = i - 1; j; --j) 
			{
				if ((f[j] == f[i] - 1) && (a[j] > a[i]) && (nex[j] > i)) g[i] += g[j];
			}
		else g[i] = 1;
		
	}
	
	cout << f[N] - 1 << ' ' ;
	g[N].print();
}

int main()
{
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);
	read();
	getans();
}
