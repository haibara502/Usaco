/*
LANG: C++
PROG: holstein
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 15, maxm = 25;
int need[maxm], con[maxn][maxm], sum[maxm];
int V, N;

void read()
{
	scanf("%d", & V);
	for (int i = 0; i < V; ++i) scanf("%d", & need[i]);
	scanf("%d", & N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < V; ++j) scanf("%d", & con[i][j]);
}

void getans()
{
	string ans = "";
	for (int i = 0; i <= N; ++i) ans += '#';
	
	for (int i = 1; i < (1 << N); ++i)
	{
		memset(sum, 0, sizeof sum);
		for (int j = 0; j < N; ++j) if (i & (1 << j))
			for (int k = 0; k < V; ++k) sum[k] += con[j][k];
		bool ff = true;
		for (int j = 0; j < V; ++j) if (sum[j] < need[j])
		{
			ff = false; break;
		}
		if (ff)
		{
			string temp = "";
			for (int j = 0; j < N; ++j) if (i & (1 << j))
				if (j < 10)
				 	temp += char(j + '0');
				 else temp += char(j - 9 + 'a');
			if (temp.size() < ans.size())
				ans = temp;
			else if ((temp.size() == ans.size()) && (temp < ans))
				ans = temp;
		}
	}
	
	cout << ans.size();
	for (int i = 0; i < ans.size(); ++i)
		if (ans[i] <= '9') cout << ' ' << ans[i] - '0' + 1;
		else cout << ' ' << ans[i] - 'a' + 10;
	cout << endl;
}

int main()
{
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	read();
	getans();
}
