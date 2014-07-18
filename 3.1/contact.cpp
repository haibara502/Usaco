/*
LANG: C++
PROG: contact
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 13, maxm = 200010, maxl = 531500;
class Poi
{
	public:
	int x, y;
	bool operator <(const Poi & Q) const
	{
		if (x != Q.x) return x > Q.x;
		string s1 = "", s2 = "";
		for (int i = y; i; i /= 3) s1 += char(i % 3 + '0');
		for (int i = Q.y; i; i /= 3) s2 += char(i % 3 + '0');
		if (s1.size() != s2.size()) return s1.size() < s2.size();
		return s1 < s2;
	}
	Poi(int x = 0, int y = 0):x(x), y(y){}
} d[maxm];
int a[maxm], sum[maxl], cf[maxn];
string s;
int A, B, N;

void read()
{
	scanf("%d%d%d", & A, & B, & N);
	string ss("");
	while (cin >> ss)
		s += ss;
}

void print(int v)
{
	int len = 0;
	for (; v; v /= 3) a[++len] = v % 3;
	for (int i = 1; i <= len; ++i) cout << a[i] - 1;
}

void getans()
{
	for (int i = 0; i < s.size(); ++i)
		a[i] = s[i] - '0' + 1;
		
	cf[0] = 1;
	for (int i = 1; i <= 12; ++i) cf[i] = cf[i - 1] * 3;
		
	for (int i = A; i <= B; ++i)
	{
		int now = 0;
		if (i > s.size()) break;
		for (int j = 0; j <= i - 1; ++j) 
			now = now + (a[j] * (cf[j]));
		++sum[now];
			
		for (int j = i; j < s.size(); ++j)
		{
			now = (now / 3) + (a[j] * cf[i - 1]);
			++sum[now];
		}
	}
	int total = 0;
	for (int i = 0; i < cf[12]; ++i) if (sum[i])
		d[++total] = Poi(sum[i], i);
	sort(d + 1, d + 1 + total);
	int l = 1;
	while (l <= total)
	{
		if (N-- == 0) break;
		int r = l;
		for (; (r < total) && (d[r + 1].x == d[l].x); ++r);
		cout << d[l].x << endl;
		for (int i = l; i < r; ++i) 
		{
			print(d[i].y);
			if ((i - l + 1) % 6) cout << ' ';
			else cout << endl;
		}
		print(d[r].y);
		cout << endl;
		l = r + 1;
	}		
}

int main()
{
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	read();
	getans();
}
