/*
LANG: C++
PROG: hidden
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
string s;

int cmp(int x, int y)
{
	int k = 0;
	for (; (k < N) && (s[x + k] == s[y + k]); ++k);
	if (k == N) return k;
	if (s[x + k] > s[y + k]) return -k;
	return k;
}

void read()
{
	scanf("%d", & N);
	string ss;
	while (cin >> ss)
		s += ss;
}

void getans()
{
	s += s;
	int x = 0;
	char w = 'z';
	for (int i = 0; i < s.size(); ++i) w = min(w, s[i]);
	while (s[x] != w) ++x;
	
	for (int i = x + 1; i <= N; )
	{
		if (s[i] != w)
		{
			++i; continue;
		}
		int k = cmp(x, i);
		if (k == N) break;
		else if (k > 0) i += k;
		else x = i++;
	}
	
	cout << x << endl;
}

int main()
{
	freopen("hidden.in", "r", stdin);
	freopen("hidden.out", "w", stdout);
	read();
	getans();
}
