/*
ID: haibara3
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long need;

void read()
{
	freopen("namenum.in", "r", stdin);
	cin >> need;
}

void getans()
{
	freopen("dict.txt", "r", stdin);
	freopen("namenum.out", "w", stdout);
	
	bool ff = false;
	string name;
	while (cin >> name)
	{
		long long now = 0;
		for (int i = 0; i < name.size(); ++i)
			if (name[i] <= 'P') now = now * 10 + ((name[i] - 'A') / 3 + 2);
			else now = now * 10 + ((name[i] - 'A' - 1) / 3 + 2);
		if (now == need) 
		{
			cout << name << endl;
			ff = true;
		}
	}
	if (!ff) cout << "NONE" << endl;
}

int main()
{
	read();
	getans();
}
