#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
 
struct position {
    int x, y;
    position(int xx = 0, int yy = 0) : x(xx), y(yy) {}
};
 
int move[8][2] = {{-1,-2}, {-2,-1}, {-2,1}, {-1,2},
                    {1,2}, {2,1}, {2,-1}, {1,-2}};
 
int nkight; 
int row, column;
 
int cost[26][30];
int kcost[26][30];
int dist[26][30];
int kdist[26][30];
int kkdist[26][30];     // original king steps
bool visited[26][30];
bool isKnight[26][30];
 
void calcCost(int sx, int sy)
{
    //int steps = 0;
    int x, y;
    position p;
 
    memset(visited, false, 30*26);
    memset(dist, 0, sizeof(int)*30*26);
    queue<position> q;
    q.push(position(sx, sy));
    //dist[sx][sy] = 1;
    visited[sx][sy] = true;
 
    //bfs alone
    while (!q.empty()) {
        p = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            x = p.x+move[i][0];
            y = p.y+move[i][1];
            // check if the next position is vaild
            if (x>=0 && x<column && y>=0 && y<row && !visited[x][y]) {
                visited[x][y] = true;
                q.push(position(x, y));
                dist[x][y] = dist[p.x][p.y] + 1;    // one move
                cost[x][y] += dist[x][y];           // add a knight
            }
        }
    }
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            kdist[i][j] = kkdist[i][j];
 
    // bfs with king
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++) {
            q.push(position(i, j));
            while (!q.empty()) {
                p = q.front(); q.pop();
                for (int k = 0; k < 8; k++) {
                    x = p.x + move[k][0];
                    y = p.y + move[k][1];
                    if (x>=0 && x<column && y>=0 && y<row) {
                        if (kdist[x][y] + dist[x][y] > dist[p.x][p.y] + kdist[p.x][p.y] + 1) {
                            kdist[x][y] = dist[p.x][p.y] + kdist[p.x][p.y] + 1 - dist[x][y];
                            q.push(position(x, y));
                        }
                    }
                }
            }
        }
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            if (kdist[i][j] < kcost[i][j])
                kcost[i][j] = kdist[i][j];
}
 
int main()
{
    char xx;
    int x, y;
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
    fin >> row >> column;
 
    fin >> xx >> y;
    x = xx - 'A';
    y --;
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++) {
            if (abs(i-x) > abs(j-y))
                kcost[i][j] = kkdist[i][j] = abs(i-x); 
            else
                kcost[i][j] = kkdist[i][j] = abs(j-y);
        }
 
    while (fin >> xx >> y) {
        x = xx - 'A';
        y --;
        isKnight[x][y] = true;
        calcCost(x, y); // bfs
    }
 
    int ans = 0xFFFFFFF;
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            if ((cost[i][j] > 0 || isKnight[i][j]) && ans > cost[i][j] + kcost[i][j]) {
            	cerr << cost[i][j] + kcost[i][j] << endl;
            	cerr << cost[i][j] << ' ' << kcost[i][j] << endl;
            	cerr << i << ' ' << j << endl;
                ans = cost[i][j] + kcost[i][j];
            }
    if (ans == 0xFFFFFFF)   //no king
        fout << 0 << endl;
    else {
        cout << ans << endl;
        fout << ans << endl;
    }
 
    fin.close();
    fout.close();
    return 0;
}
