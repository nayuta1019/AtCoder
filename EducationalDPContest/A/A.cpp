/**
2019/01/06/ 自力AC
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

int main(){
    int N;
    cin >> N;
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    FOR(i, 2, N){
        dp[i] = min(dp[i-2]+abs(h[i] - h[i-2]), dp[i-1]+abs(h[i] - h[i-1]));
    }

    cout << dp[N-1] << endl;

    return 0;
}