/*
LANG: C++
PROG: comehome
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

const int maxn = 60, maxm = 20010, cs = 1073741823;
int g1[maxn], next[maxm], f[maxm], s[maxm];
bool p[maxn];
int di[maxn], d[maxm * maxn];
int N, total;

int calc(char v)
{
	if (isupper(v)) return (v - 'A' + 1 + 26);
	else return (v - 'a' + 1);
}

void init(int i, int j , int k)
{
	s[++total] = j; next[total] = g1[i]; g1[i] = total; f[total] = k;
}

void read()
{
	scanf("%d", & N);
	memset(g1, 0, sizeof g1);
	total = 0;
	
	for (int i = 1; i <= N; ++i)
	{
		char a, b; int c;
		cin >> a >> b>> c;
		int a1 = calc(a), b1 = calc(b);
		init(a1, b1, c);
		init(b1, a1, c);
	}
}

void getans()
{
	d[1] = 52;
	memset(p, false, sizeof p);
	p[52] = true; di[52] = 0;
	int closed = 0, open = 1;
	for (int i = 1; i < 52; ++i) di[i] = cs;
	while (closed < open)
	{
		int t = d[++closed];
		for (int temp = g1[t]; temp; temp = next[temp]) if (di[t] + f[temp] < di[s[temp]])
		{
			di[s[temp]] = di[t] + f[temp];
			if (!p[s[temp]])
				d[++open] = s[temp], p[s[temp]] = true;
		}
		p[t] = false;
	}
	int ans = cs, temp1 = -1;
	for (int i = 27; i < 52; ++i) if (di[i] < ans)
		ans = di[i], temp1 = i - 26 - 1;
	cout << char(temp1 + 'A') << ' ' << ans << endl;
	
}

int main()
{
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	read();
	getans();
}
