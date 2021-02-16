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
    vector<ll> d(b);
    rep(i, b) cin >> d[i];
    sort(all(d));
    ll ans = n;

    rep(i, b){
        if(i == 0){
            if(a < d[i]){
                ans -= d[i]/a;
            }
        }

        if(i < b-1){
            if(a < d[i+1] - d[i] - 1){
                ans -= (d[i+1]-d[i]-1)/a; 
            }
        }
        
        if(i == b-1){
            if(a <= n - d[i]){
                ans -= (n-d[i])/a;
            }
        }
        ans -= 1;
    }
    if(b == 0){
        ans = n / a;
    }
    if(a == 1){
        ans = 0;
    }

    cout << ans << endl;


    return 0;
}