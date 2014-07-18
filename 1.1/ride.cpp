/*
ID: haibara3
PROG: ride
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	long long sum_a = 1, sum_b = 1;
	for (int i = 0; i < a.size(); ++i) sum_a = (sum_a * (a[i] - 'A' + 1)) % 47;
	for (int i = 0; i < b.size(); ++i) sum_b = (sum_b * (b[i] - 'A' + 1)) % 47;
	if (sum_a == sum_b) cout << "GO" << endl;
	else cout << "STAY" << endl;
}

