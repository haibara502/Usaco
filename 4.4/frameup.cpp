/*
LANG: C++
PROG: frameup
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 30;
char a[maxn][maxn];
int up[256], down[256], Left[256], Right[256];
bool show[256];
int N, M, ans;
string an[100010];

void read()
{
	scanf("%d%d", & N, & M);
	for (int i = 0; i < N; ++i) scanf("%s", a[i]);
}

bool check(char w)
{
	for (int i = up[w]; i <= down[w]; i += down[w] - up[w])
		for (int j = Left[w]; j <= Right[w]; ++j) if ((a[i][j] != w) && (a[i][j] != '#')) return false;
	for (int j = Left[w]; j <= Right[w]; j += Right[w] - Left[w])
		for (int i = up[w]; i <= down[w]; ++i) if ((a[i][j] != w) && (a[i][j] != '#')) return false;
	return true;
}

void cancel(char w)
{
	for (int i = up[w]; i <= down[w]; i += down[w] - up[w])
		for (int j = Left[w]; j <= Right[w]; ++j) a[i][j] = '#';
	for (int j = Left[w]; j <= Right[w]; j += Right[w] - Left[w])
		for (int i = up[w]; i <= down[w]; ++i) a[i][j] = '#';
}

void dfs(string now)
{
	bool ff = false;
	for (int i = 'A'; i <= 'Z'; ++i) if (show[i])
	{
		ff = true;
		if (check(i))
		{
			show[i] = false;
			char temp[30][30];
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < M; ++k) temp[j][k] = a[j][k];
			cancel(i);
			dfs(char(i) + now);
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < M; ++k) a[j][k] = temp[j][k];
			show[i] = true;
		}
	}
	if (!ff)
		an[++ans] = now;
}

void getans()
{
	memset(show, false, sizeof show);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) show[a[i][j]] = true;
	for (int i = 'A'; i <= 'Z'; ++i)
		up[i] = N + 1, down[i] = -1, Left[i] = M + 1, Right[i] = -1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) if (isupper(a[i][j]))
		{
			char w = a[i][j];
			up[w] = min(up[w], i);
			down[w] = max(down[w], i);
			Left[w] = min(Left[w], j);
			Right[w] = max(Right[w], j);
		}
	ans = 0;
	dfs("");
	sort(an + 1, an + 1 + ans);
	for (int i = 1; i <= ans; ++i) cout << an[i] << endl;
}

int main()
{
	freopen("frameup.in", "r", stdin);
	freopen("frameup.out", "w", stdout);
	read();
	getans();
}
