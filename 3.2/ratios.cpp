/*
ID: haibara3
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int a[maxn][maxn];

void read()
{
	for (int j = 0; j < 3; ++j) scanf("%d", & a[3][j]);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) scanf("%d", & a[i][j]);
}

void getans()
{
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			for (int k = 0; k < 101; ++k) if (i + j + k) 
			{
				bool ff = true;
				if ((a[3][0]) && ((a[0][0] * i + a[1][0] * j + a[2][0] * k) % a[3][0] != 0)) continue;
				int biao = (a[0][0] * i + a[1][0] * j + a[2][0] * k) / a[3][0];
				for (int l = 1; l < 3; ++l) 
					if ((a[3][l]) && ((((a[0][l] * i + a[1][l] * j + a[2][l] * k) % a[3][l]) != 0) || ((a[0][l] * i + a[1][l] * j + a[2][l] * k) / a[3][l] != biao)))
					{
						ff = false; break;
					}
				if (ff)
				{
					cout << i << ' ' << j << ' ' << k << ' ' << biao << endl;
					return;
				}
			}
	cout << "NONE" << endl;
}

int main()
{
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
	read();
	getans();
}
