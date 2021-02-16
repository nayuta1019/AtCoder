/**
ABC015
2018/12/20/ 解説AC
author:mhrb
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

//dp[i][j][l] i番目まで調べたときの、幅合計l、使用枚数jの最大値
int dp[55][55][10005];

int main(){
    int w, n, k;
    cin >> w >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    FOR(i, 1, n+1){
        FOR(j, 1, k+1){
            rep(l, w+1){
                if( a[i-1] <= l){
                    dp[i][j][l] = max(dp[i-1][j][l], dp[i-1][j-1][l-a[i-1]] + b[i-1]);
                }else{
                    dp[i][j][l] = dp[i-1][j][l];
                }
            }
        }
    }

    cout << dp[n][k][w] << endl;

    return 0;
}