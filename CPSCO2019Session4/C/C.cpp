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

    ll n, d;
    cin >> n >> d;
    vector<ll> r(n);
    rep(i, n) cin >> r[i];
    sort(all(r));

    int right = 0;
    ll ans = 0;
    rep(left, n){
        while(right < n && r[right] <= r[left] + d) right++;
        
        ans += (ll)(right-left-1)*(ll)(right-left-2)/2;
    }

    cout << ans << endl;

    return 0;
}
