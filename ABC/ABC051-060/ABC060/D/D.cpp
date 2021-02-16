/**
ABC060
2019/01/18/ 解説AC
author:null_null
long long にする
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

template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template <typename T> void chmin(T &a, T b) { a = min(a, b); }

ll N, W;
ll v[110], w[110];
vector<ll> wary[5];

int main(){
    cin >> N >> W;
    rep(i, N){
        cin >> w[i] >> v[i];
        ll ww = w[i] - w[0];
        wary[ww].push_back(v[i]);
    }

    for(ll i = 0; i < 4; i++){
        sort(wary[i].begin(), wary[i].end());
        wary[i].push_back(0);
        reverse(wary[i].begin(), wary[i].end());
        for(ll j = 1; j < wary[i].size(); j++){
            wary[i][j] += wary[i][j-1];
        }
    }

    ll ans = 0;
    for(ll i = 0; i < wary[0].size(); i++){
        for(ll j = 0; j < wary[1].size(); j++){
            for(ll k = 0; k < wary[2].size(); k++){
                for(ll l = 0; l < wary[3].size(); l++){
                    if( (i + j + k + l) * w[0] + j + 2 * k + 3 * l > W ){
                        continue;
                    }

                    ll sum = wary[0][i] + wary[1][j] + wary[2][k] + wary[3][l];
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}