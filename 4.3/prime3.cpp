/*
LANG: C++
PROG: prime3
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 11, maxm = 6;
bool can[maxn][maxn][maxn][maxn][maxn];
int a[maxm][maxm], d[maxm], sum;
string an[10010];

void read()
{
	scanf("%d%d", & sum, & a[1][1]);
}

void prepare()
{
	for (int i = 10001; i < 100000; ++i)
	{
		bool ff = true;
		for (int j = 2; j <= (int)sqrt(i); ++j) if (i % j == 0)
		{
			ff = false; break;
		}
		if (!ff) continue;
		int len = 0;
		for (int v = i; v; v /= 10) d[++len] = v % 10;
		can[d[5]][d[4]][d[3]][d[2]][d[1]] = true;
		can[d[5]][d[4]][10][10][10] = can[d[5]][d[4]][d[3]][10][10] = true;
		can[d[5]][d[4]][d[3]][d[2]][10] = true;
		can[10][10][10][d[2]][d[1]] = true;
		can[10][10][d[3]][d[2]][d[1]] = true;
		can[10][d[4]][d[3]][d[2]][d[1]] = true;
	}
}

void getans()
{
	prepare();
	
	int ans = 0;
	for (a[1][5] = 1; a[1][5] < 10; ++a[1][5]) if ((a[1][5] & 1) && (a[1][5] != 5))
		for (a[2][5] = 1; a[2][5] < 10; ++a[2][5]) if ((a[2][5] & 1) && (a[2][5] != 5) && can[a[1][5]][a[2][5]][10][10][10])
			for (a[3][5] = 1; a[3][5] < 10; ++a[3][5]) if ((a[3][5] & 1) && (a[3][5] != 5) && can[a[1][5]][a[2][5]][a[3][5]][10][10])
				for (a[4][5] = 1; a[4][5] < 10; ++a[4][5]) if ((a[4][5] & 1) && (a[4][5] != 5) && can[a[1][5]][a[2][5]][a[3][5]][a[4][5]][10])
				{
					a[5][5] = sum - a[1][5] - a[2][5] - a[3][5] - a[4][5];
					if ((a[5][5] < 0) || (a[5][5] > 9)) continue;
					if (!can[a[1][5]][a[2][5]][a[3][5]][a[4][5]][a[5][5]]) continue;
					for (a[2][2] = 0; a[2][2] < 10; ++a[2][2]) if (can[a[1][1]][a[2][2]][10][10][10])
						for (a[3][3] = 0; a[3][3] <10; ++a[3][3]) if (can[a[1][1]][a[2][2]][a[3][3]][10][10])
						{
							a[4][4] = sum - a[1][1] - a[2][2] - a[3][3] - a[5][5];
							if ((a[4][4] < 0) || (a[4][4] > 9)) continue;
							if (!can[a[1][1]][a[2][2]][a[3][3]][a[4][4]][a[5][5]]) continue;
							if (!can[10][10][10][a[4][4]][a[4][5]]) continue;
							for (a[2][4] = 0; a[2][4] < 10; ++a[2][4])
							{
								if (!can[10][10][a[3][3]][a[2][4]][a[1][5]]) continue;
								if (!can[10][10][10][a[2][4]][a[2][5]]) continue;
								for (a[4][2] = 0; a[4][2] < 10; ++a[4][2]) if (can[10][a[4][2]][a[3][3]][a[2][4]][a[1][5]])
								{
									a[5][1] = sum - a[4][2] - a[3][3] - a[2][4] - a[1][5];
									if ((a[5][1] <= 0) || (a[5][1] > 9)) continue;
									if (!can[a[5][1]][a[4][2]][a[3][3]][a[2][4]][a[1][5]]) continue;
									for (a[2][3] = 0; a[2][3] < 10; ++a[2][3]) if (can[10][a[2][2]][a[2][3]][a[2][4]][a[2][5]])
									{
										a[2][1] = sum - a[2][2] - a[2][3] - a[2][4] - a[2][5];
										if ((a[2][1] <= 0) || (a[2][1] > 9)) continue;
										if (!can[a[2][1]][a[2][2]][a[2][3]][a[2][4]][a[2][5]]) continue;
										for (a[4][3] = 0; a[4][3] < 10; ++a[4][3]) if (can[10][a[4][2]][a[4][3]][a[4][4]][a[4][5]])
										{
											a[4][1] = sum - a[4][2] - a[4][3] - a[4][4] - a[4][5];
											if ((a[4][1] <= 0) || (a[4][1] > 9)) continue;
											if (!can[a[4][1]][a[4][2]][a[4][3]][a[4][4]][a[4][5]]) continue;
											a[3][1] = sum - a[1][1] - a[2][1] - a[4][1] - a[5][1];
											if ((a[3][1] <= 0) || (a[3][1] > 9)) continue;
											if (!can[a[1][1]][a[2][1]][a[3][1]][a[4][1]][a[5][1]]) continue;
											for (a[3][2] = 0; a[3][2] < 10; ++a[3][2]) if (can[a[3][1]][a[3][2]][a[3][3]][10][10])
											{
												a[3][4] = sum - a[3][1] - a[3][2] - a[3][3] - a[3][5];
												if ((a[3][4] < 0) || (a[3][4] > 9)) continue;
												if (!can[a[3][1]][a[3][2]][a[3][3]][a[3][4]][a[3][5]]) continue;
												for (a[1][2] = 1; a[1][2] < 10; ++a[1][2]) if (can[a[1][2]][a[2][2]][a[3][2]][a[4][2]][10])
												{
													a[5][2] = sum - a[1][2] - a[2][2] - a[3][2] - a[4][2];
													if ((a[5][2] < 0) || (a[5][2] > 9)) continue;
													if (!can[a[1][2]][a[2][2]][a[3][2]][a[4][2]][a[5][2]]) continue;
													for (a[1][3] = 1; a[1][3] < 10; ++a[1][3]) 
													{
														if (!can[a[1][1]][a[1][2]][a[1][3]][10][10]) continue;
														if (!can[a[1][3]][a[2][3]][a[3][3]][a[4][3]][10]) continue;
														a[5][3] = sum - a[1][3] - a[2][3] - a[3][3] - a[4][3];
														if ((a[5][3] < 0) || (a[5][3] > 9)) continue;
														if (!can[a[1][3]][a[2][3]][a[3][3]][a[4][3]][a[5][3]]) continue;
														a[5][4] = sum - a[5][1] - a[5][2] - a[5][3] - a[5][5];
														if ((a[5][4] < 0) || (a[5][4] > 9)) continue;
														if (!can[a[5][1]][a[5][2]][a[5][3]][a[5][4]][a[5][5]]) continue;
														if (!can[10][a[2][4]][a[3][4]][a[4][4]][a[5][4]]) continue;
														a[1][4] = sum - a[1][1] - a[1][2] - a[1][3] - a[1][5];
														if ((a[1][4] < 0) || (a[1][4] > 9)) continue;
														if (a[1][4] + a[2][4] + a[3][4] + a[4][4] + a[5][4] != sum) continue;
														if (!can[a[1][1]][a[1][2]][a[1][3]][a[1][4]][a[1][5]]) continue;
														if (!can[a[1][4]][a[2][4]][a[3][4]][a[4][4]][a[5][4]]) continue;
														string now("");
														for (int i = 1; i <= 5; ++i)
														{
															for (int j = 1; j <= 5; ++j) now += char(a[i][j] + '0');
															now += '\n';
														}
														an[++ans] = now;
													}
												}
											}
										}
									}
								}
							}
						}
				}	
	if (!ans)
	{
		cout << "NONE" << endl;
		return;
	}
	sort(an + 1, an + 1 + ans);
	for (int i = 1; i < ans; ++i) cout << an[i] << endl;
	cout << an[ans];
}

int main()
{
	freopen("prime3.in", "r", stdin);
	freopen("prime3.out", "w", stdout);
	read();
	getans();
}
