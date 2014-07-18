/*
LANG: C++
PROG: sprime
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int a[4] = {2, 3, 5, 7}, b[4] = {1, 3, 7, 9};
int N;

void read()
{
	scanf("%d", & N);
}

bool check(int v)
{
	bool ff = true;
	for (int i = 2; i <= (int)sqrt(v); ++i)
		if (v % i == 0) 
		{
			ff = false; break;
		}
	return ff;
}

void dfs(int now, int ceng, int need)
{	
	if (ceng == 1)
		for (int i = 0; i < 4; ++i)
		{
			now = a[i];
			if (ceng == need) cout << now << endl;
			else dfs(now, ceng + 1, need);
		}
	else
		for (int i = 0; i < 4; ++i)
		{
			now = now * 10 + b[i];
			if (check(now))
				if (ceng == need) cout << now << endl;
				else dfs(now, ceng + 1, need);
			now /= 10;
		}
}

void getans()
{
	dfs(0, 1, N);	
}

int main()
{
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	read();
	getans();
}
