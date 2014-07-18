/*
LANG: C++
PROG: lamps
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 210;
int set[maxn];
int N, C;
int an[maxn];

void read()
{
	scanf("%d", & N);
	scanf("%d", & C);
	
	memset(set, -1, sizeof set);
	int a; scanf("%d", & a);
	while (a != -1)
	{
		a = (a - 1) % 6 + 1;
		set[a] = 1;
		scanf("%d", & a);
	}
	scanf("%d", & a);
	while (a != -1)
	{
		a = (a - 1) % 6 + 1;
		if (set[a] == 1)
		{
			cout << "IMPOSSIBLE" << endl;
			exit(0);
		}
		set[a] = 0;
		scanf("%d", & a);
	}
}

void print(int v)
{
	for (int i = 1; i <= N; ++i)
	{
		int j = (i - 1) % 6 + 1;
		if (v & (1 << j)) printf("1");
		else printf("0");
	}
	printf("\n");
}

inline bool cmp(const int & i, const int & j)
{
	string i1 = "", j1 = "";
	for (int k = 1; k < 7; ++k)
	{
		i1 = i1 + char(bool(i & (1 << k)) + '0');
		j1 = j1 + char(bool(j & (1 << k)) + '0');
	}
	return i1 < j1;
}

void getans()
{
	int ans = 0;
	for (int i = 0; i < (1 << 4); ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 4; ++j) if (i & (1 << j)) ++cnt;
		if (((cnt & 1) != (C & 1)) || (cnt > C)) continue;
		int now = (1 << 7) - 1;
		if (i & 1)
			for (int j = 1; j < 7; ++j) now ^= (1 << j);
		if (i & (1 << 1))
			for (int j = 1; j < 7; j += 2) now ^= (1 << j);
		if (i & (1 << 2))
			for (int j = 2; j < 7; j += 2) now ^= (1 << j);
		if (i & (1 << 3))
			for (int j = 1; j < 7; j += 3) now ^= (1 << j);
		bool check = true;
		for (int j = 1; j < 7; ++j) if (set[j] != -1)
		{
			bool ff = now & (1 << j);
			if (ff != set[j]) check = false;
		}
		if (!check) continue;
		an[++ans] = now;
	}
	if (ans == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	sort(an + 1, an + 1 + ans, cmp);
	print(an[1]);
	for (int i = 2; i <= ans; ++i) if (an[i] != an[i - 1]) print(an[i]);
}

int main()
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	read();
	getans();
}
