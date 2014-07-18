/*
LANG: C++
PROG: prefix
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 210;
string ss, a[maxn];
int N;
bool f[maxn];

void read()
{
	N = 0;
	string s;
	cin >> s;
	ss = "#";
	while (s != ".")
	{
		a[++N] = s;
		cin >> s;
	}
	while (cin >> s) ss += s;
}

bool can(int i, int j)
{
	for (int l = 0; l < a[j].size(); ++l)
		if (ss[i - (int)a[j].size() + 1 + l] != a[j][l]) return false;
	return true;
}

void getans()
{
	memset(f, false, sizeof f);
	f[0] = true;
	for (int i = 1; i < ss.size(); ++i)
	{
		for (int j = 1; j <= N; ++j) if ((i >= a[j].size()) && (can(i, j)))
		{
			f[i] |= f[i - a[j].size()];
			if (f[i]) break;
		}
	}
	for (int i = ss.size() - 1; i >= 0; --i) if (f[i]) 
	{
		cout << i << endl;
		break;
	}
}

int main()
{
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	read();
	getans();
}
