/*
LANG: C++
PROG: runround
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20;
long long now;
int M;
bool show[maxn], used[maxn];

void read()
{
	scanf("%d", & M);
}

string zhuan(long long v)
{
	string ans = "";
	for (; v; v /= 10)
		ans = (char(v % 10 + '0')) + ans;
	return ans;
}

bool check(long long v)
{
	string temp = zhuan(v);
	bool ff = true;
	int pos = 0;
	memset(show, false, sizeof show);
	for (int i = 0; i < temp.size(); ++i)
	{
		pos = (pos + temp[pos] - '0') % temp.size();
		if (show[pos])
		{
			ff = false; break;
		}
		show[pos] = true;
	}
	return ff;
}

void dfs(int deep, int need)
{
	if (deep > need + 1) return;
	if ((now > M) && (check(now)))
	{
		cout << now << endl;
		exit(0);
	}
	for (int i = 1; i <= 9; ++i) if (!used[i])
	{
		used[i] = true;
		now = now * 10 + i;
		dfs(deep + 1, need);
		used[i] = false;
		now /= 10;
	}
}

void getans()
{
	int N = zhuan(M).size();
	for (; N <= 100; ++N)
	{
		memset(used, false, sizeof used);
		now = 0;
		dfs(1, N);
	}
}

int main()
{
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	read();
	getans();
}
