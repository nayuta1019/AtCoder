/**
2018/10/26/ 解説AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>
#include <queue>

using namespace std;

const int INF = 1 << 21;

int R, C;
int sx, sy, gx, gy;
char m[100][100];
int dist[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


int bfs(void){
    queue< pair<int, int> > que;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            dist[i][j] = INF;
        }
    }

    que.push( make_pair(sx, sy) );
    dist[sy][sx] = 0;

    while( que.size() ){
        
        pair<int, int> q = que.front();
        que.pop();

        if(q.first == gx && q.second == gy){
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = q.first + dx[i];
            int ny = q.second + dy[i];

            if(0 <= nx && nx <= C-1 && 0 <= ny && ny <= R-1 && m[ny][nx] != '#' && dist[ny][nx] == INF){
                que.push( make_pair(nx, ny) );
                dist[ny][nx] = dist[q.second][q.first] + 1;

            }
        }
    }

    return dist[gy][gx];

}

int main(){

    cin >> R >> C >> sy >> sx >> gy >> gx;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> m[i][j];
        }
    }

    sy--;
    sx--;
    gy--;
    gx--;

    cout << bfs() << endl;
    

    return 0;
}