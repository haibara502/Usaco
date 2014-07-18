/*
PROG: pprime
LANG: C++
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

const int a[4] = {1, 3, 7, 9}, maxn = 1000100;
string now;
int A, B, ans;
int an[maxn];

void read()
{
	scanf("%d%d", & A, & B);
}

void check()
{
	string temp = now;
	int len = now.size();
	for (int i = len - 1; i >= 0; --i) now += now[i];
	int number = 0;
	for (int i = 0; i < now.size(); ++i) number = number * 10 + now[i] - '0';
	if ((number >= A) && (number <= B))
	{
		bool ff = true;
		for (int i = 2; i < (int)sqrt(number); ++i)
			if (number % i == 0)
			{
				ff = false; break;
			}
		if (ff) an[++ans] = number;
	}
	now = temp;
	for (int i = len - 2; i >= 0; --i) now += now[i];
	number = 0;
	for (int i = 0; i < now.size(); ++i) number = number * 10 + now[i] - '0';
	if ((number >= A) && (number <= B))
	{
		bool ff = true;
		for (int i = 2; i <= (int)sqrt(number); ++i)
			if ((number % i) == 0)
			{
				ff = false; break;
			}
		if (ff) an[++ans] = number;
	}
	now = temp;
}

void dfs(int ceng, int need)
{
	if (ceng > need) return;
	if (ceng == 1)
	{
		for (int i = 1; i < 10; ++i) 
		{
			now = char(i + '0');
			check();
		}
		
		for (int i = 0; i < 4; ++i)
		{
			now = char(a[i] + '0');
			dfs(ceng + 1, need);
		}
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		string temp = now;
		now =  now + char(i + '0');
		check();
		dfs(ceng + 1, need);
		now = temp;
	}
}

void getans()
{
	string now;
	dfs(1, 4);
	sort(an + 1, an + 1 + ans);
	for (int i = 1; i <= ans; ++i) cout << an[i] << endl;
}

int main()
{
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	read();
	getans();
}
