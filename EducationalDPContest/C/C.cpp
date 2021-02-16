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
    vector<int> a(N), b(N), c(N);
    rep(i, N){
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<int> adp(N), bdp(N), cdp(N);
    adp[0] = a[0];
    bdp[0] = b[0];
    cdp[0] = c[0];
    FOR(i, 1, N){
        adp[i] = a[i] + max(bdp[i-1], cdp[i-1]);
        bdp[i] = b[i] + max(adp[i-1], cdp[i-1]);
        cdp[i] = c[i] + max(adp[i-1], bdp[i-1]);
    }

    cout << max({adp[N-1], bdp[N-1], cdp[N-1]}) << endl;

    return 0;
}