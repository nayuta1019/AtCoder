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
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    vector<int> dp(N, 1e9);
    dp[0] = 0;
    FOR(i, 1, N){
        if(i < K){
            for(int j = i-1; 0 <= j; j--){ 
                dp[i] = min(dp[j]+abs(h[i] - h[j]), dp[i]);
            }
        }else{
            for(int j = i-1; i-K <= j; j--){ 
                dp[i] = min(dp[j]+abs(h[i] - h[j]), dp[i]);
            }
        }
    }
    
    cout << dp[N-1] << endl;

    return 0;
}