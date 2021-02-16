#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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

    ll n, a, b; cin >> n >> a >> b;
    vector<ll> d;
    d.push_back(0);
    rep(i, b){
        ll x; cin >> x;
        d.push_back(x);
    }
    d.push_back(n+1);
    sort(all(d));

    ll ans = 0;
    rep(i, b+1){
        ll tmp = d[i+1] - d[i] - 1;
        ans += tmp - tmp / a;
    }

    cout << ans << endl;
    
    return 0;
}