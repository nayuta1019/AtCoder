/**
ATC001
2019/03/13/ 解説AC
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

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

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int H, W, sx, sy, gx, gy;
char c[555][555];
bool visited[555][555];

void dfs(int x, int y){

    if(x < 0 || y < 0 || W <= x || H <= y || c[y][x] == '#') return ;
    if(visited[y][x]) return ;

    visited[y][x] = true;

    rep(i, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> H >> W;
    rep(i, H) rep(j, W){
        cin >> c[i][j];
        if(c[i][j] == 's') sx = j, sy = i;
        if(c[i][j] == 'g') gx = j, gy = i;
    }

    dfs(sx, sy);
    if(visited[gy][gx]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}