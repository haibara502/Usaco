/*
LANG: C++
PROG: lgame
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 40010, value[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int showStd[257], show[257];
string a[maxn], std1;
int score[maxn];

void read()
{
	cin >> std1;
	memset(showStd, 0, sizeof showStd);
	for (int i = 0; i < std1.size(); ++i) ++showStd[std1[i]];
}

int calc(string ss)
{
	int sum = 0;
	for (int i = 0; i < ss.size(); ++i) sum += value[ss[i] - 'a'];
	return sum;
}

bool can(int i, int j)
{
	memset(show, 0, sizeof show);
	for (int k = 0; k < a[i].size(); ++k) if (++show[a[i][k]] > showStd[a[i][k]]) return false;
	for (int k = 0; k < a[j].size(); ++k) if (++show[a[j][k]] > showStd[a[j][k]]) return false;
	return true;
}

void getans()
{
	int N = 0;
	string ss;
	cin >> ss;
	for (; ss != "."; cin >> ss)
	{
		memset(show, 0, sizeof show);
		bool ff = true;
		for (int i = 0; i < ss.size(); ++i) if (++show[ss[i]] > showStd[ss[i]])
		{
			ff = false; break;
		}
		if (!ff) continue;
		a[++N] = ss;
		score[N] = calc(ss);
	}
	
	int ans = 0;
	for (int i = 1; i<= N; ++i) 
	{
		ans = max(ans, score[i]);
		for (int j = i; j <= N; ++j) if (can(i, j))
			ans = max(ans, score[i] + score[j]);
	}
	
	cout << ans << endl;
	for (int i = 1; i <= N; ++i)
	{
		if (score[i] == ans) cout << a[i] << endl;
		for (int j = i; j <= N; ++j) if ((can(i, j) && (score[i] + score[j] == ans)))
			cout << a[i] << ' ' << a[j] << endl;
	}
}

int main()
{
	freopen("lgame.in", "r", stdin);
	freopen("lgame.out", "w", stdout);
	read();
	freopen("lgame.dict", "r", stdin);
	getans();
}
