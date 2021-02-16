/**
ABC118
2019/02/16/ 自力AC
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

// 最大公約数
long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// 最小公倍数
long long lcm(long long a, long long b){
    long long g = gcd(a,b);
    return a / g * b; // Be careful not to overflow
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ans = a[0];
    for(int i = 1; i < n; i++){
        ans = gcd(ans, a[i]);
    }

    cout << ans << endl;

    return 0;
}