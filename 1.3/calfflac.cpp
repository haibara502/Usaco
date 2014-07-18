/*
ID: haibara3
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

const int maxn = 1100;
string ss, s;

void read()
{
	while (getline(cin, s))
	{
		if (ss != "") ss += "#";
		ss += s;
	}
}

void zuo(int &v)
{
	--v;
	while ((v >= 0) && (!isalpha(ss[v]))) --v;
}

void you(int & v)
{
	++v;
	while ((v < ss.size()) && (!isalpha(ss[v]))) ++v;
}

void getans()
{
	int ans = 1, begin = 0, end = 0;
	//type1
	for (int i = 0; i < ss.size(); ++i) if (ss[i] != '#')
	{
		int length = 1;
		int l = i, r = i;
		while (1)
		{
			zuo(l), you(r);
			if ((l < 0) || (r >= ss.size())) break;
			if (tolower(ss[l]) == tolower(ss[r])) length += 2;
			else break;
			if (length > ans)
				ans = length, begin = l, end = r;
		}
	}
	
	//tupe2
	for (int i = 0; i < ss.size() - 1; ++i)
	{
		int length = 0;
		int l = i + 1, r = i;
		while (1)
		{
			zuo(l), you(r);
			if ((l < 0) || (r >= ss.size())) break;
			if (tolower(ss[l]) == tolower(ss[r])) length += 2;
			else break;
			if (length > ans)
				ans = length, begin = l, end = r;
		}
		
	}
	
	cout << ans << endl;
	for (int i = begin; i <= end; ++i) 
		if (ss[i] != '#') cout << ss[i];
		else cout << endl;
	cout << endl;
	cerr << ans << endl;
}

int main()
{
	freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);
	read();
	getans();
}
