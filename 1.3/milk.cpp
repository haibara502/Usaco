/*
ID: haibara3
PROG: milk
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5010;
class Poi
{
	public:
		int price, amount;
	bool operator <(const Poi & Q) const
	{
		return price < Q.price;
	}
} cow[maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
	for (int i = 1; i <= M; ++i) scanf("%d%d", & cow[i].price, & cow[i].amount);
}

void getans()
{
	sort(cow + 1, cow + 1 + M);
	long long ans = 0;
	for (int i = 1; i <= M; ++i)
	{
		ans += (long long)min(N, cow[i].amount) * cow[i].price;
		if (N <= cow[i].amount) break;
		else N -= cow[i].amount;
	}
	cout << ans << endl;
}

int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	read();
	getans();
}
