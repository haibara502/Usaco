/*
LANG: C++
PROG: hamming
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 8;
int an[70];
int N, B, D;

void read()
{
	scanf("%d%d%d", & N, & B, & D);
}

void getans()
{
	int ans = 1;
	an[1] = 0;
	
	for (int i = 1; i < (1 << B); ++i)
	{
		bool ff = true;
		for (int j = 1; j <= ans; ++j)
		{
			int now = an[j] ^ i, sum = 0;
			for (int k = 0; k < B; ++k) if (now & (1 << k)) ++sum;
			if (sum < D)
			{
				ff = false; break;
			}
		}
		if (ff) 
		{
			an[++ans] = i;
			if (ans == N) break;
		}
	}
	for (int i = 1; i < ans; ++i) 
		if (i % 10 != 0) cout << an[i] << ' ';
		else cout << an[i] << endl;
	cout << an[ans] << endl;
}

int main()
{
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	read();
	getans();
}
