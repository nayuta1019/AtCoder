/**
ABC106
2019/04/01/ 解説AC
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

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector< vector<int> > city(N+2, vector<int>(N+2, 0));
    rep(i, M){
        int L, R;
        cin >> L >> R;
        city[R][L] += 1;
    }
    rep(i, N+1) rep(j, N+1) city[i][j+1] += city[i][j];

    rep(_, Q){
        int p, q, ans = 0;
        cin >> p >> q;
        FOR(i, p, q+1) ans += city[i][q] - city[i][p-1];
        cout << ans << endl;
    }

    return 0;
}