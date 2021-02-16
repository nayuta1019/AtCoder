/**
AISingPC2019
2019/01/15/ 解説
author:betrue12
**/
#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > Mat;
typedef tuple<int, int, int, int> T;
typedef pair<int, int> P;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
    int H, W;
    cin >> H >> W;
    string S[400];
    for(int i = 0; i < H; i++) cin >> S[i];

    bitset<400> visited[400];

    ll ans = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(visited[i][j]) continue;
            visited[i][j] = true;
            vector<ll> num(2, 0);
            queue<pair<int, int>> que;
            que.push({i, j});

            while(que.size()){
                auto p = que.front();
                que.pop();
                int x = p.first;
                int y = p.second;
                num[S[x][y] == '#']++;

                for(int k = 0; k < 4; k++){
                    int x2 = x + dx[k];
                    int y2 = y + dy[k];
                    if(0 <= x2 && x2 < H && 0 <= y2 && y2 < W && !visited[x2][y2] && S[x][y] != S[x2][y2]){
                        que.push({x2, y2});
                        visited[x2][y2] = true;
                    }
                }
            }
            ans += num[0] * num[1];
        }
    }

    cout << ans << endl;

    return 0;
}