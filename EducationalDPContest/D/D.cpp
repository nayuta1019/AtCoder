/**
2019/01/06/ 未完成
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

ll dp[100005];

int main(){
    int N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i, N){
        cin >> w[i] >> v[i];
        dp[w[i]] = v[i];
    }

    rep(i, N){
        ll weight = w[i];
        rep(j, N){
            
            if(weight + w[j] <= W){
                dp[weight+w[j]] = max(dp[weight], dp[weight]+v[j]);
                weight += w[j];
            }
        }
    }

    sort(dp, dp+W+1, greater<ll>());

    cout << dp[0] << endl;

    return 0;
}