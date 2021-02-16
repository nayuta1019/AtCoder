/**
AGC033
2019/05/04/ 未完成
2019/05/06/ 自力AC
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

int H, W;
char A[1010][1010];
int m[1010][1010];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    queue< pair<int, int> > que;
    cin >> H >> W;
    rep(y, H){
        rep(x, W){
            cin >> A[y][x];
            if(A[y][x] == '#') que.push(make_pair(x, y));
        }
    }

    while(!que.empty()){
        pair<int, int> p = que.front();
        que.pop();

        rep(i, 4){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < W && 0 <= ny && ny < H && A[ny][nx] == '.' ){
                m[ny][nx] = m[p.second][p.first] + 1;
                A[ny][nx] = '#';
                que.push(make_pair(nx, ny));
            }
        }
    }

    int ans = 0;
    rep(i, H) rep(j, W) ans = max(ans, m[i][j]);

    cout << ans << endl;

    return 0;
}