/**
AISingPC2019
2019/01/12/ 未完成
2019/01/15/ 自力AC
**/
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
typedef pair<int, int> P;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

char m[401][401];
bool d[401][401];
int H, W;
ll b, w, ans;

int dfs(int x, int y){

    if(m[y][x] == '#') b++;
    if(m[y][x] == '.') w++;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
		int ny = y + dy[i];

        //  壁を越えないかつ、行ったことのない場所なら
		if(0 <= nx && nx <= W-1 && 0 <= ny && ny <= H-1 && d[ny][nx] == false && m[y][x] != m[ny][nx]){ 
            d[ny][nx] = true;
            dfs(nx, ny);
		}
    }
    
    return 0;
}

int main(){

    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> m[i][j];

    ll res = 0;
    rep(i, H){
        rep(j, W){
            if(m[i][j] == '#'){
                d[i][j] = true;
                b = 0; w = 0;
                dfs(j, i);
                //cout << "b = " << b << " w = " << w << endl;
                ans += b * w;
            }
        }
    }

    cout << ans << endl;

    return 0;
}