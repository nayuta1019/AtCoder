/**
ABC054
2018/12/20/ 解説AC
dp
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

const int nmax = 40, abmax = 10;

int a[nmax], b[nmax], c[nmax];
int dp[nmax+1][nmax*abmax+1][nmax*abmax+1];

int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 0; i <= n; i++){
        for(int ca = 0; ca <= nmax*abmax; ca++){
            for(int cb = 0; cb <= nmax*abmax; cb++){
                dp[i][ca][cb] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int ca = 0; ca <= nmax*abmax; ca++){
            for(int cb = 0; cb <= nmax*abmax; cb++){
                if(dp[i][ca][cb] == INF) continue;
                dp[i+1][ca][cb] = min(dp[i+1][ca][cb], dp[i][ca][cb]);
                dp[i+1][ca+a[i]][cb+b[i]] = min(dp[i+1][ca+a[i]][cb+b[i]], dp[i][ca][cb]+c[i]);

            }
        }
    }

    int ans = INF;
    for(int ca = 1; ca <= nmax*abmax; ca++){
        for(int cb = 1; cb <= nmax*abmax; cb++){
            if(ca*mb == cb*ma) ans = min(ans, dp[n][ca][cb]);
        }
    }

    if(ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
}