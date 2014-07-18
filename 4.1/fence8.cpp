/*
LANG: C++
PROG: fence8
ID: haibara3
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 51, maxm = 1024;
int board[maxn], rail[maxm], sumR[maxm];
int N, M;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & board[i]);
	scanf("%d", & M);
	for (int i = 1; i <= M; ++i) scanf("%d", & rail[i]);
}

inline bool cmp(const int & i, const int & j)
{
	return i > j;
}

bool dfs(int board_num, int rail_num)
{
//	cerr << board_num << ' '<< rail_num << endl;
	if ((rail_num == 0) || (sumR[M] <= rail[1]))
		return true;
		
	int sum_board = 0;
	for (int i = 1; i <= N; ++i) 
		if (board[i] >= rail[1]) sum_board += board[i];
	if (sum_board < sumR[rail_num]) return false;
	
	for (int i = 1; i <= N; ++i) if (board[i] == rail[rail_num])
	{
		board[i] = 0;
		bool ff = dfs(1, rail_num - 1);
		board[i] = rail[rail_num];
		return ff;
	}
	
	bool ff = false;
	for (int i = board_num; i <= N; ++i) if ((board[i] != board[i - 1]) && (board[i] >= rail[rail_num]))
	{
		board[i] -= rail[rail_num];
		if (rail[rail_num] == rail[rail_num - 1])
			ff |= dfs(i, rail_num - 1);
		else ff |= dfs(1, rail_num - 1);
		board[i] += rail[rail_num];
		if (ff) return true;
	}
	return false;
}

void getans()
{
	sort(board + 1, board + 1 + N, cmp);
	sort(rail + 1, rail + 1 + M);
	for (int i = 1; i <= M; ++i) sumR[i] = sumR[i - 1] + rail[i];

	
	int l = 1, r = 1, ans = 0;
	for (; (r < M) && (rail[r + 1] <= board[1]); ++r);
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (dfs(1, mid))
			l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
	
	
	//cerr << dfs(1, 8) << endl;
}

int main()
{
	freopen("fence8.in", "r", stdin);
	freopen("fence8.out", "w", stdout);
	read();
	getans();
}
