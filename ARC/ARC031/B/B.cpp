/**
ARC031
2019/03/19/ 解説AC
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


char island[10][10];
bool used[10][10];

void dfs(int x, int y){

    rep(i, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < 10 && 0 <= ny && ny < 10 && island[ny][nx] == 'o' && used[ny][nx] == false){
            used[ny][nx] = true;
            dfs(nx, ny);
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    rep(i, 10) rep(j, 10) cin >> island[i][j];
    

    bool flag = false;
    rep(i, 10) rep(j, 10){
        if(island[i][j] == 'o') continue;
        
        island[i][j] = 'o';
        rep(p, 10) rep(q, 10) used[p][q] = false;
        used[i][j] = true;
        dfs(j, i);
        
        bool f = true;
        rep(p, 10) rep(q, 10){
            if(island[p][q] == 'x') continue;
            if(!used[p][q]) f = false;
        }
        flag |= f;

        used[i][j] = false;
        island[i][j] = 'x';
    }

    cout<<(flag ? "YES":"NO")<<endl;

    return 0;
}