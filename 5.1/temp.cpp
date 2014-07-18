#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", a[i].x, a[i].y);
}

bool check(Poi a, Poi b, Poi c)
{
	return cha(a.x - b.x. a.y - b.y, b.x - c.x, b.y - c.y) >= 0;
}

void getans()
{
	sort(a + 1, a + 1 + N);
	
	int open = 0;
	for (int i = 1; i <= N; ++i)
	{
		while ((open > 1) && (check(d[open - 1], d[open], a[i]))) --open;
		d[++open] = a[i];
	}
	
	int limit = open;
	for (int i = N; i; --i)
	{
		while ((open > limit) && (check(d[open - 1], d[open], a[i]))) --open;
		d[++open] = a[i];
	}
	
	
}

int main()
{
	read();
	getans();
}
