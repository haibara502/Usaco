/*
LANG: C++
PROG: twofive
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
string s;
char maxRow[6], maxCol[6];
bool used[257];
int f[6][6][6][6][6], a[5];

void prepare(int i, int j)
{
	maxRow[i / 5] = maxCol[i % 5] = j;
	used[j] = true;
	memset(f, 0, sizeof f);
	f[5][5][5][5][5] = 1;
}

int dp(int a, int b, int c, int d, int e, char w) 
{
	int &ans = f[a][b][c][d][e];
	if (ans) return ans;
	if (used[w]) return ans = dp(a, b, c, d, e, w + 1);
	ans = 0;
	if(a < 5 && w > maxCol[0] && w > maxRow[a])
		ans += dp(a + 1, b, c, d, e, w + 1);
	if(b < a && w > maxCol[1] && w > maxRow[b])
		ans += dp(a, b + 1, c, d, e, w + 1);
	if(c < b && w > maxCol[2] && w > maxRow[c])
		ans += dp(a, b, c + 1, d, e, w + 1);
	if(d < c && w > maxCol[3] && w > maxRow[d])
		ans += dp(a, b, c, d + 1, e, w + 1);
	if(e < d && w > maxCol[4] && w > maxRow[e])
		ans += dp(a, b, c, d, e + 1, w + 1);
	return ans;
}
void getans_N()
{
	scanf("%d", & N);
	for (int i = 0; i <= 5; ++i) maxRow[i] = maxCol[i] = 'A' - 1;
	for (int i = 0; i < 25; ++i)
	{
		++a[i % 5];
		for (int j = 'A'; j < 'Z'; ++j)
			if ((j > maxRow[i / 5]) && (j > maxCol[i % 5]) && (!used[j]))
			{
				prepare(i, j);
				int sum = dp(a[0], a[1], a[2], a[3], a[4], 'A');
				if (N > sum)
					N -= sum, used[j] = false;
				else 
				{
					cout << (char)j; break;
				}
			}
	}
	cout << endl;
}

void getans_W()
{
	int ans = 1;
	for (int i = 0; i < 25; ++i)
	{
		++a[i % 5];
		for (int j = 'A'; j < s[i]; ++j)
			if ((j > maxRow[i / 5]) && (j > maxCol[i % 5]) && (!used[j]))
			{
				prepare(i, j);
				int sum = dp(a[0], a[1], a[2], a[3], a[4], 'A');
				ans += sum;
				used[j] = false;
			}
		used[s[i]] = true;
		maxRow[i / 5] = maxCol[i % 5] = s[i];
	}
	cout << ans << endl;
}
int main()
{
	freopen("twofive.in", "r", stdin);
	freopen("twofive.out", "w", stdout);
	char T; scanf("%c", & T);
	switch (T)
	{
		case 'N': 
			getans_N();
			break;
		case 'W':
			cin >> s;
			getans_W();
	}
}
