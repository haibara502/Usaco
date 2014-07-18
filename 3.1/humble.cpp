/*
LANG: C++
PROG: humble
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 110;
int a[maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

void getans()
{
	set<long long> numbers;
	numbers.clear();
	for (int i = 1; i <= N; ++i) numbers.insert(a[i]);
	for (int i = 1; i <= N; ++i) 
	{
		int v = a[i];
		for (set<long long>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		{
			long long temp = v * (*it);
			if (temp < 0) break;
			if (numbers.size() > M)
			{
				numbers.erase(--numbers.end());
				if (temp > *(--numbers.end())) break;
			}
			numbers.insert(temp);
		}
	}
	cout << *(--numbers.end()) << endl;
}

int main()
{
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	read();
	getans();
}
