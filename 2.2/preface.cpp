/*
LANG: C++
PROG: preface
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 3510;
const string ans = "IVXLCDM";
int sum[257], N;
string an[maxn];

void read()
{
	scanf("%d", & N);
}

string biao(int v)
{
	if (an[v] != "#") return an[v];
	string ans = "";
	if (v / 1000)
	{
		for (int i = 1; i <= v / 1000; ++i) ans += 'M';
		ans += biao(v % 1000);
	}
	else if (v / 100)
	{
		int a = v / 100;
		if (a <= 3)
			for (int i = 1; i <= a; ++i) ans += 'C';
		else if (a <= 8)
		{
			ans = 'D';
			if (a == 4) ans = 'C' + ans;
			for (int i = 6; i <= a; ++i) ans += 'C';
		}
		else ans = "CM";
		ans += biao(v % 100);		
	}
	else if (v / 10)
	{
		int a = v / 10;
		if (a <= 3)
			for (int i = 1; i <= a; ++i) ans += 'X';
		else if (a <= 8)
		{
			ans = 'L';
			if (a == 4) ans = 'X' + ans;
			for (int i = 6; i <= a; ++i) ans += 'X';
		}
		else ans = "XC";
		ans += biao(v % 10);
	}
	else
		if ((v >= 1) && (v <= 3))
			for (int i = 1; i <= v; ++i) ans += 'I';
		else if ((v >= 4) && (v <= 8))
		{
			ans = 'V';
			for (int i = 6; i <= v; ++i) ans += 'I';
			if (v == 4) ans = 'I' + ans;
		}
		else ans = "IX";
	return ans;
}

void getans()
{
	for (int i = 1; i <= N; ++i) an[i] = "#";
	for (int i = 1; i <= N; ++i) an[i] = biao(i);
	for (int i = 1; i <= N; ++i)
	{
//		cerr << i << ' ' << an[i] << endl;
		for (int j = 0; j < an[i].size(); ++j) ++sum[an[i][j]];
	}
	for (int i = 0; i < ans.size(); ++i) if (sum[ans[i]])
		cout << ans[i] << ' ' << sum[ans[i]] << endl;
}

int main()
{
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	read();
	getans();
}
