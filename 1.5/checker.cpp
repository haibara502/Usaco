/*
LANG: C++
PROG: checker
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 15;
int N;
int shu, ans;
long long xiehe, xiecha;
int an[maxn];

void read()
{
	scanf("%d", & N);
}

void dfs(int ceng, int need)
{
	if (ceng == need)
	{
		if (++ans <= 3)
		{
			for (int i = 0; i < need - 1; ++i) cout << an[i] + 1 << ' ';
			cout << an[need - 1] + 1 << endl;
		}
		return;
	}
//	cerr << ceng << ' ' << shu << ' ' << xiehe << ' ' << xiecha << endl;
	for (int i = 0; i < N; ++i)
		if (!(shu & (1 << i)) && !(xiehe & (1 << (i + ceng))) && !(xiecha & (1 << (i - ceng + N - 1))))
		{
			shu |= (1 << i);
			xiehe |= (1 << (i + ceng));
			xiecha |= (1 << (i - ceng + N - 1));
			an[ceng] = i;
			dfs(ceng + 1, need);
			shu ^= (1 << i);
			xiehe ^= (1 << (i + ceng));
			xiecha ^= (1 << (i - ceng + N - 1));
		}
}

void getans()
{
	int shu = 0, xiehe = 0, xiecha = 0;
	dfs(0, N);	
	cout << ans << endl;
}

int main()
{
	freopen("checker.in", "r", stdin);
	freopen("checker.out", "w", stdout);
	read();
	getans();
}
