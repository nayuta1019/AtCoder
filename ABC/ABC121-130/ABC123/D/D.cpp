/**
ABC123
2019/04/06/ 解説AC
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

    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z), p;
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    rep(i, X){
        rep(j, Y){
            p.push_back(A[i] + B[j]);
        }
    }
    sort(p.begin(), p.end(), greater<ll>());

    vector<ll> tmp;
    int pp = min((ll)p.size(), K);
    rep(i, pp) tmp.push_back(p[i]);

    vector<ll> ans;
    rep(i, pp){
        rep(j, Z) ans.push_back(tmp[i]+C[j]);
    }

    sort(ans.begin(), ans.end(), greater<ll>());

    rep(i, K){
        cout << ans[i] << endl;
    }

    return 0;
}