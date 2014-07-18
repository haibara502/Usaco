/*
LANG: C++
PROG: msquare
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 8 * 8 * 8 * 8 * 8 * 8 * 8;
bool p[8][8][8][8][8][8][8];
int c[8];
class Poi
{
	char w;
	int a[8], b[8], pr;
	
	public:
	void read()
	{
		for (int i = 0; i < 8; ++i) scanf("%d", & a[i]);
	}
	void mark()
	{
		p[a[0] - 1][a[1] - 1][a[2] - 1][a[3] - 1][a[4] - 1][a[5] - 1][a[6] - 1] = true;
	}
	void zhuan(int e, int pre)
	{
		pr = pre;
		switch (e)
		{
			case 0:
				for (int i = 0; i < 4; ++i) b[i] = a[i], a[i] = a[i + 4];
				for (int i = 4; i < 8; ++i) a[i] = b[i - 4];
				w = 'A';
				break;
			case 1:
				b[0] = a[3], b[4] = a[7];
				for (int i = 3; i > 0; --i) 
					a[i] = a[i - 1], a[i + 4] = a[i + 4 - 1];
				a[0] = b[0], a[4] = b[4];
				w = 'B';
				break;
			case 2:
				b[1] = a[1], a[1] = a[5], a[5] = a[6], a[6] = a[2], a[2] = b[1];
				w = 'C';
		}
	}
	void begin()
	{
		for (int i = 0; i < 4; ++i) a[i] = i + 1;
		for (int i = 4; i < 8; ++i) a[i] = 12 - i;
	}
	bool pan()
	{
		return p[a[0] - 1][a[1] - 1][a[2] - 1][a[3] - 1][a[4] - 1][a[5] - 1][a[6] - 1];
	}
	bool succ()
	{
		for (int i = 0; i < 8; ++i) if (a[i] != c[i]) 
			return false;
		return true;
	}
	int pre()
	{
		return pr;
	}
	char way()
	{
		return w;
	}
	void print()
	{
		for (int i = 0 ;i < 8; ++i) cerr << a[i] << ' ';
		cerr << endl;
	}
} d[40400];
	
void read()
{
	for (int i = 0; i < 4; ++i) cin >> c[i];
	for (int i = 4; i < 8; ++i) cin >> c[11 - i];
}

void getans()
{
	d[1].begin();
	d[1].mark();
	int closed = 0, open = 1;
	while (closed < open)
	{
		++closed;
		for (int e = 0; e < 3; ++e)
		{
			Poi d1 = d[closed];
			d1.zhuan(e, closed);
			if (d1.pan()) continue;
			d[++open] = d1, d1.mark();
			
			if (d1.succ())
			{
				string ans = "";
				for (int open1 = open; open1 != 1; open1 = d[open1].pre())
					ans = d[open1].way() + ans;
				cout << ans.size() << endl;
				for (int i = 0; i < ans.size(); ++i)
				{
					cout << ans[i];
					if ((i + 1) % 60 == 0) cout << '\n';
				}
				cout << endl;
				return;
			}
			
		}
	}
	cout << 0 << endl << endl;
}

int main()
{
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
	read();
	getans();	
}
