/*
ID: haibara3
PROG: friday
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10;
int sum[maxn];

int main()
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int N; scanf("%d", & N);
	int year = 1900, month = 1, day = 13 % 7;
	while (year <= 1900 + N - 1)
	{
		++sum[day];
		switch (month)
		{
			case 1:
			case 3: 
			case 5: 
			case 7: 
			case 8: 
			case 10:
			case 12:
				day = (day + 31) % 7;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				day = (day + 30) % 7;
				break;
			case 2:
				if (year % 100 == 0)
					if (year % 400 == 0) day = (day + 29) % 7;
					else day = (day + 28) % 7;
				else if (year % 4 == 0)
					day = (day + 29) % 7;
				else day = (day + 28) % 7;
		}
		++month; if (month > 12) month = 1, ++year;
	}
	cout << sum[6];
	for (int i = 0; i < 6; ++i) cout << ' ' << sum[i];
	cout << endl;
}
