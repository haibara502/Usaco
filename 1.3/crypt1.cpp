/*
ID: haibara3
LANG: C++
PROG: crypt1
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int a[maxn], b[maxn], c[maxn], d[maxn], q[maxn];
bool show[maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & q[i]);
	memset(show, false, sizeof show);
	for (int i = 1; i <= N; ++i) show[q[i]] = true;
}

void getans()
{
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			for (int k = 1; k <= N; ++k)
				for (int l = 1; l <= N; ++l)
					for (int m = 1; m <= N; ++m)
					{
						a[0] = q[i], a[1] = q[j], a[2] = q[k];
						b[0] = q[l], b[1] = q[m];
						
						c[0] = 0;
						for (int o = 1; o <= 3; ++o) c[o] = a[o - 1] * b[1];
						for (int o = 3; o > 1; --o) c[o - 1] += c[o] / 10, c[o] %= 10;
						
						bool ff = true;
						for (int o = 1; o <= 3; ++o) if (!show[c[o]]) ff = false;
						if (!ff) continue;
						
						for (int o = 0; o < 3; ++o) d[o] = a[o] * b[0];
						for (int o = 2; o > 0; --o) d[o - 1] += d[o] / 10, d[o] %= 10;
						for (int o = 0; o < 3; ++o) if (!show[d[o]]) ff = false;
						if (!ff) continue;
						
						d[3] = 0;
						for (int o = 1; o <= 3; ++o) d[o] += c[o];
						for (int o = 3; o; --o) d[o - 1] += d[o] / 10, d[o] %= 10;
						for (int o = 0; o < 4; ++o) if (!show[d[o]]) ff = false;
						if (!ff) continue;
						
						/*
						for (int o = 0; o < 3; ++o) cerr << a[o];
						cerr << endl;
						cerr << ' ';
						for (int o = 0; o < 2; ++o) cerr << b[o];
						cerr << endl;
						for (int o = 1; o <= 3; ++o) cerr << c[o];
						cerr << endl;
						for (int o = 0; o <= 3; ++o) cerr << d[o];
						cerr << endl;
						cerr << endl;
						*/
						++ans;
					}
	cout << ans << endl;
//	cerr << ans << endl;
}

int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	read();
	getans();
}
