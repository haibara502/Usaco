/*
LANG: C++
PROG: latin
ID: haibara3
*/	
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10;
bool visit[maxn], row[maxn][maxn], col[maxn][maxn];
int a[maxn], cnt[maxn];
int N, id;
long long ans;

void read()
{
	scanf("%d", & N);
}

int find()
{
	int len = 1;
	memset(visit, false, sizeof visit);
	for (int i = 1; i <= N; ++i) if (!visit[i])
	{
		int tempLen = 0, j = i;
		do
		{
			visit[j] = true;
			++tempLen;
			j = a[j];
		} while (j != i);
		len = max(len, tempLen);
	}
	return len;
}

void dfs(int x, int y)
{
	for (int i = 1; i <= N; ++i) if (row[x][i] && col[y][i])
	{
		if (x == 2)
		{
			a[y] = i;
			if (y == N)
			{
				id = find();
				if (cnt[id]) 
				{
					ans += cnt[id]; return;
				}
			}
		}
		
		row[x][i] = col[y][i] = false;
		if (y == N)
			if (x == N - 1)
				++cnt[id], ++ans;
			else dfs(x + 1, 2);
		else dfs(x, y + 1);
		
		row[x][i] = col[y][i] = true;
	}
}

void getans()
{
	if (N == 2) 
	{
		cout << 1<< endl;
		return;
	}
	memset(row, true, sizeof row);
	memset(col, true, sizeof col);
	memset(cnt, 0, sizeof cnt);
	for (int i = 2; i < N; ++i) row[i][i] = false;
	for (int i = 1; i <= N; ++i) col[i][i] = false;
	ans = 0;
	a[1] = 2;
	dfs(2, 2);
	for (int i = 1; i < N; ++i) ans *= i;
	cout << ans << endl;
}

int main()
{
	freopen("latin.in", "r", stdin);
	freopen("latin.out", "w", stdout);
	read();
	getans();
}
