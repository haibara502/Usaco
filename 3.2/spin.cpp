/*
LANG: C++
PROG: spin
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 6, maxm = 360;
class Wheel
{
	int speed, dongl[6], dongr[6], sum;
	public:
	void read()
	{
		scanf("%d%d", & speed, & sum);
		for (int i = 1; i <= sum; ++i) 
		{
			scanf("%d%d", & dongl[i], & dongr[i]);
			dongr[i] += dongl[i];
		}
	}
	int duan() const
	{
		return sum;
	}
	int begin(int i, int tme)
	{
		return (dongl[i] + speed * tme) % 360;
	}
	int end(int i, int tme)
	{
		return (dongr[i] + speed * tme) % 360;
	}
} wheel[maxn];
int fx[maxn][maxm];

void read()
{
	for (int i = 1; i <= 5; ++i) wheel[i].read();
}

void getans()
{
	for (int tme = 0; tme < 360; ++tme)
	{
		memset(fx, 0, sizeof fx);
		for (int i = 1; i <= 5; ++i)	
			for (int j = 1; j <= wheel[i].duan(); ++j)
			{
				int l = wheel[i].begin(j, tme), r = wheel[i].end(j, tme);
//				cerr << i << ' ' << j << ' ' << l << ' ' << r << endl;
				if (l >= r) r += 360;
				for (int k = l; k <= r; ++k) fx[i][k % 360] = true;
			}
		for (int i = 0; i < 360; ++i) 
		{
			bool ff = true;
			for (int j = 1; j <= 5; ++j) if (!fx[j][i]) ff = false;
			if (ff)
			{
				cout << tme << endl;
				return;
			}
		}
	}
	cout << "none" << endl;
}

int main()
{
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
	read();
	getans();
}
