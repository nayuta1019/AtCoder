/**
2018/10/25/ 未完成
2018/10/26/ 完成(解説AC)
配列のxとyの位置に注意！！
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

#define INF 100000

typedef pair<int, int> P;
 
int H, W;
int sx, sy;
int gx, gy;
char m[100][100];
int d[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int i, j;
 
int bfs(void){
	
	queue<P> que;
	
	for(i = 0; i < H; i++){
		for(j = 0; j < W; j++){
			d[i][j] = INF;  //  INFで初期化
		}
	}
	
    //  スタート位置
	que.push( P(sx, sy) );
	d[sy][sx] = 0;
	
	while( que.size() ){

		P p = que.front();
		que.pop();

		if(p.first == gx && p.second == gy){
			break;
		}

		for(i = 0; i < 4; i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

            //  壁を越えないかつ、行ったことのない場所なら
			if(0 <= nx && nx <= W-1 && 0 <= ny && ny <= H-1 && m[ny][nx] != '#' && d[ny][nx] == INF){   
				que.push( P(nx, ny) );
				d[ny][nx] = d[p.second][p.first] + 1;
			}

		}

	}

    if(d[gy][gx] == INF) d[gy][gx] = -1;
	return d[gy][gx];
}

int main(){
    int block = 0;
    cin >> H >> W;
    for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){
            cin >> m[i][j];
            if(m[i][j] == '#') block++;
        }
    }

    sx = sy = 0;
    gx = W-1;
    gy = H-1;

    int res = bfs();
    
    int ans;
    if(res != -1) ans = H * W - block - res - 1;
    else ans = res;
    

    cout << ans << endl;

    return 0;
}