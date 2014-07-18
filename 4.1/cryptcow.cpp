/*
LANG: C++
PROG: cryptcow
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const string ss = "Begin the Escape execution at the Break of Dawn";
const int maxn = 257, cs1 = 1000003, cs2 = 99997;
bool p[cs1];
int show[maxn], d[maxn];
string s;
int std1;

void read()
{
	getline(cin, s);
}

int hash(string now)
{
	unsigned long seed = 131313, hash = 0;
	for (int i = 0; i < now.size(); ++i) hash = hash * seed + now[i];
    return (hash & 0x7FFFFFFF) % cs1;
}

bool check(string now)
{
	for (int i = 0; i < ss.size(); ++i)
	{
		if (now[i] == 'C') break;
		if (ss[i] != now[i]) return false;
	}
	for (int i = 0; i < ss.size(); ++i)
	{
		if (now[now.size() - i - 1] == 'W') break;
		if (ss[ss.size() - i - 1] != now[now.size() - i - 1]) return false;
	}
	int open = 0;
	for (int i = 0; i < now.size(); ++i) if ((now[i] == 'C') || (now[i] == 'O') || (now[i] == 'W'))
		d[++open] = i;
	for (int i = 2; i <= open; ++i)
	{
		bool ff = false;
		int len = d[i] - d[i - 1] - 1;
		for (int j = 0; j < ss.size() - len; ++j)
		{
			bool f = true;
			for (int k = 1; k <= len; ++k) 
				if (now[d[i - 1] + k] != ss[j + k - 1]) 
				{
					f = false; break;
				}
			if (f) 
			{
				ff = true; break;
			}
		}
		if (!ff) return false;
	}
	return true;
}

string zhuan(string now, int c, int o, int w)
{
	string temp("");
	for (int i = 0; i < c; ++i) temp += now[i];
	for (int i = o + 1; i < w; ++i) temp += now[i];
	for (int i = c + 1; i < o; ++i) temp += now[i];
	for (int i = w + 1; i < now.size(); ++i) temp += now[i];
	return temp;	
}

bool dfs(int step, string now)
{
	int ha = hash(now);
	if (p[ha]) return false;
	else if (ha == std1)
	{
		cout << 1 << ' ' << step << endl;
		return true;
	}
	p[ha] = true;
	if (check(now) == false) return false;
	for (int o = 1; o < now.size() - 1; ++o) if (now[o] == 'O')
		for (int c = 0; c < o; ++c) if (now[c] == 'C')
			for (int w = now.size() - 1; w > o; --w) if (now[w] == 'W')
			{
				string temp = zhuan(now, c, o, w);
				if (dfs(step + 1, temp)) return true;
			}
	return false;
}

void getans()
{
	memset(p, false, sizeof p);
	if (s.size() < ss.size()) 
	{
		cout << "0 0" << endl;
		return;
	}
	if (((s.size() - ss.size()) % 3) != 0) 
	{
		cout << "0 0" << endl;
		return;
	}
	memset(show, 0, sizeof show);
	for (int i = 0; i < s.size(); ++i) ++show[s[i]];
	for (int i = 0; i < ss.size(); ++i) --show[ss[i]];
	for (int i = 'A'; i <= 'z'; ++i) if ((i != 'C') && (i != 'O') && (i != 'W'))
		if (show[i])
		{
			cout << "0 0" << endl;
			return;
		}
	std1 = hash(ss);
	bool ff = dfs(0, s);
	if (!ff) cout << "0 0" << endl;
}

int main()
{
	freopen("cryptcow.in", "r", stdin);
	freopen("cryptcow.out", "w", stdout);
	read();
	getans();
}
