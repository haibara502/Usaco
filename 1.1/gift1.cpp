/*
ID: haibara3
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int maxn = 1100;
int have[maxn];
string Name[maxn];

int main()
{
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	map<string, int> ku;
	ku.clear();
	int N;
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i)
	{
		string name;
		cin >> name;
		ku[name] = i;
		Name[i] = name;
	}
	memset(have, 0, sizeof have);
	for (int i = 1; i <= N; ++i)
	{
		string name;
		cin >> name;
		int person = ku[name];
		int money, sum; 
		cin >> money >> sum;
		have[person] -= money;
		for (int j = 1; j <= sum; ++j)
		{
			string name1;
			cin >> name1;
			int person1 = ku[name1];
			have[person1] += money / sum;
		}
		if (sum) have[person] += money % sum;
		else have[person] += money;
	}
	for (int i = 1; i <= N; ++i)
		cout << Name[i] << ' ' << have[i] << endl;
}
