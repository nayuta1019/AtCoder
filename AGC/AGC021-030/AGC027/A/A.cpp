/**
AGC027
2019/03/14/ 解説AC
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

    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());
    
    ll ans = 0, sum = 0;
    for(int i = 0; i < N; i++){
        if(a[i] <= x) x -= a[i], ans++;
    }
    if(ans == N && x != 0) ans--;

    cout << ans << endl;

    return 0;
}