/*
LANG: C++
PROG: beads
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

void read()
{
	cin >> N;
	cin >> s;
}

void getans()
{
	for (int i = 0; i < N; ++i) s += s[i];
	int ans = 1;
	for (int i = 0; i < (N << 1) - 1; ++i)
	{
		int l = i, r = i + 1;
		char cl = s[i], cr = s[i + 1];
		for (; (l > 0) && ((cl == 'w') || (s[l - 1] == 'w') || (s[l - 1] == cl)); --l) if (cl == 'w') cl = s[l - 1];
		for (; (r < (N << 1) - 1) && ((cr == 'w') || (s[r + 1] == 'w') || (s[r + 1] == cr)); ++r) if (cr == 'w') cr = s[r + 1];	
		ans = max(ans, r - l + 1);
		ans = min(ans, N);
//		cerr << i << ' ' << l << ' ' << r << ' ' << ans << cl << ' ' << cr << endl;
	}
	cout << ans << endl;
}

int main()
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	read();
	getans();
}
