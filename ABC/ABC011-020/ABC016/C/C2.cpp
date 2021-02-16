/**
ABC016
2018/12/21/ 解説AC
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

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int dist[20][20];

int main(){
    int N, M;
    cin >> N >> M;
    
    rep(i, N) rep(j, N) dist[i][j] = INF;
    rep(i, N) dist[i][i] = 0;

    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        dist[a][b] = dist[b][a] = 1;
    }

    //ワーシャルフロイド
    rep(k, N)
        rep(i, N)
            rep(j, N)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    rep(i, N){
        int ans = 0;
        rep(j, N){
            if(dist[i][j] == 2) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}