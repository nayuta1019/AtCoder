/**
ABC063
2019/04/25/ 解説AC
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

ll n, a, b;
vector<ll> h;

bool func(ll s){
    ll res = 0;
    rep(i, n){
        ll p = h[i] - s * b;
        if(p > 0) res += (p + a - b - 1) / (a - b);
    }
    if(res <= s) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> n >> a >> b;
    h.resize(n);
    rep(i, n) cin >> h[i];

    ll r = 1e10;
    ll l = -1;

    //二分探索
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if(func(mid)) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}