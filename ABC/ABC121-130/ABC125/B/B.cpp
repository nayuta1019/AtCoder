/**
ABC125
2019/04/27/ 自力AC
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

    int n;
    cin >> n;
    vector<int> v(n), c(n);
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> c[i];

    int ans = 0;
    for(int bit = 0; bit < (1<<n); bit++){
        int x = 0, y = 0;
        rep(i, n){
            if(bit>>i & 1){
                x += v[i];
                y += c[i];
            }
        }

        ans = max(ans, x-y);
    }

    cout << ans << endl;

    return 0;
}