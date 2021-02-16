/**
ABC100
2019/02/20/ 解説AC
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
typedef tuple<ll, ll, ll> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector< vector<ll> > cake(3, vector<ll>(N));
    rep(i, N) cin >> cake[0][i] >> cake[1][i] >> cake[2][i];

    ll ans = -(1LL << 60);
    for(int bit = 0; bit < 8; bit++){
        vector<ll> xyz;
        for(int i = 0; i < N; i++){
            ll sum = 0;
            for(int k = 0; k < 3; k++){
                if(bit>>k & 1) sum -= cake[k][i];
                else sum += cake[k][i];
            }
            xyz.push_back(sum);
        }
        sort(xyz.begin(), xyz.end(), greater<ll>());
        ll total = 0;
        rep(i, M) total += xyz[i];
        ans = max(ans, total);
    }

    cout << ans << endl;

    return 0;
}