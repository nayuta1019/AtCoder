/**
ABC018
2018/12/12/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};


int R, C, K;
char s[510][510];
int dist[510][510];
bool used[510][510];
queue< pair<int, int> > q;

void bfs(){
    while( !q.empty() ){
        pair<int, int> p = q.front();
        q.pop();
        int xx = p.second, yy = p.first;
        if(K-1 <= dist[yy][xx]) continue;

        for(int i = 0; i < 4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx < 0 || C <= nx || ny < 0 || R <= ny) continue;
            if(used[ny][nx] == true) continue;

            dist[ny][nx] = dist[yy][xx] + 1;
            used[ny][nx] = true;
            q.push(pair<int, int>(ny, nx));
        }
    }
}

int main(){
    cin >> R >> C >> K;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> s[i][j];
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(s[i][j] == 'x'){
                q.push(make_pair(i, j));
                used[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }

    bfs();

    /**
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << used[i][j];
        }
        cout << endl;
    }
    **/

    int cnt = 0;
    for(int i = K-1; i < R - K + 1; i++){
        for(int j = K-1; j < C - K + 1; j++){
            if(used[i][j] == false) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
