/*
LANG: C++
PROG: theme
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5010;
int a[maxn];
int N;

void read()
{
	int pre;
	scanf("%d%d", & N, & pre);
	for (int i = 1; i < N; ++i)
	{
		int now; scanf("%d", & now);
		a[i] = now - pre;
		pre = now;
	}
}
 
void getans()
{
	int ans = 0;
	for (int i = 1; i < N - ans; ++i)
		for (int j = i + ans; j < N - ans; ++j) if (a[i] == a[j])
		{
			int len = 1;
			for (; (a[i + len] == a[j + len]) && (j > i + len + 1); ++len);
			ans = max(ans, len);
		}
	if (ans + 1 < 5) cout << 0 << endl;
	else cout << ans + 1 << endl;
}
 
int main()
{
	freopen("theme.in", "r", stdin);
	freopen("theme.out", "w", stdout);
	read();
	getans();
}
