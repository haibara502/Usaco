/*
LANG: C++
ID: haibara3
PROG: clocks
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 12;
int a[maxn], move[maxn], an[maxn], d[1000000];

void read()
{
	for (int i = 0; i < 9; ++i)
	{
		int a1; scanf("%d", & a1);
		a[i] = (a1 / 3) % 4;
	}
}

void getans()
{
	int ans = 1073741824;
	memset(an, 0, sizeof an);
	for (move[1] = 0; move[1] < 4; ++move[1])
		for (move[2] = 0; move[2] < 4; ++move[2])
			for (move[3] = 0; move[3] < 4; ++move[3])
				for (move[4] = 0; move[4] < 4; ++move[4])
					for (move[5] = 0; move[5] < 4; ++move[5])
						for (move[6] = 0; move[6] < 4; ++move[6])
							for (move[7] = 0; move[7] < 4; ++move[7])
								for (move[8] = 0; move[8] < 4; ++move[8])
									for (move[9] = 0; move[9] < 4; ++move[9])
										if (((a[0] + move[1] + move[2] + move[4]) % 4 == 0)
										  &&((a[1] + move[1] + move[2] + move[3] + move[5]) % 4 == 0)
										  &&((a[2] + move[2] + move[3] + move[6]) % 4 == 0)
										  &&((a[3] + move[1] + move[4] + move[5] + move[7]) % 4 == 0)
										  &&((a[4] + move[1] + move[3] + move[5] + move[7] + move[9]) % 4 == 0)
										  &&((a[5] + move[3] + move[5] + move[6] + move[9]) % 4 == 0)
										  &&((a[6] + move[4] + move[7] + move[8]) % 4 == 0)
										  &&((a[7] + move[5] + move[7] + move[8] + move[9]) % 4 == 0)
										  &&((a[8] + move[6] + move[8] + move[9]) % 4 == 0))
										{
											int total = 0;
											for (int i = 1; i <= 9; ++i) total += move[i];
											if (total < ans)
											{
												ans = total;
												for (int i = 1; i <= 9; ++i) an[i] = move[i];
											}
										}
	int len = 0;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= an[i]; ++j) d[++len] = i;
	for (int i = 1; i < len; ++i) cout << d[i] << ' ';
	cout << d[len] << endl;
}

int main()
{
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	read();
	getans();
}
