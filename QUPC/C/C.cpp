/**
2018/10/20/ 未完成
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <queue>

using namespace std;

int H, W, X, startx, starty, goalx, goaly;
char s[1100][1100];

static const int INFTY = (1 << 21);

int d[1100][1100];   //  距離で訪問状態(color)を管理する

int bfs(int sx, int sy){
    queue<int> q;   //  標準ライブラリ
    q.push(s);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            d[i][j] = INFTY;    //  全ての頂点について、d[u]をINFTYに設定
        }
    }
    d[sx][sy] = 0;

    int u;
    while( !q.empty() ){
        u = q.front();
        q.pop();

        for(int v = 0; v < n; v++){
            if( s[u][v] == '#' ) continue;
            if( d[u][v] != INFTY ) continue;
            d[u][v] = d[u] + 1;
            q.push(v);
        }
    }

    
}



int main(){
    

    cin >> H >> W >> X;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> s[i][j];
            if(s[i][j] == 'S'){
                startx = i;
                starty = j;
            }
            if(s[i][j] == 'G'){
                goalx = i;
                goaly = j;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s[i][j] == '@'){
                s[i][j] = '#';

                if(s[i][j+1] == 'G'){
                    cout << "-1" << endl;
                    return 0;
                }else{
                    s[i][j+1] = '#';
                }

                if(s[i-1][j] == 'G'){
                    cout << "-1" << endl;
                    return 0;
                }else{
                    s[i-1][j] = '#';
                }

                if(s[i][j-1] == 'G'){
                    cout << "-1" << endl;
                    return 0;
                }else{
                    s[i][j-1] = '#';
                }

                if(s[i+1][j] == 'G'){
                    cout << "-1" << endl;
                    return 0;
                }else{
                    s[i+1][j] = '#';
                }
            }
        }
    }

    bfs(startx, starty);


    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << s[i][j];
        }
        cout << endl;
    }


    return 0;
}