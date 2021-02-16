/**
2019/05/08/ 自力AC
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

    int n, d;
    cin >> n >> d;
    string s[11];
    rep(i, d) cin >> s[i];
    
    int ans = 0, p = 0, c[3] = {};
    for(int bit = 0; bit < (1<<d); bit++){
        p = 0;
        rep(k, d){
            if(bit>>k & 1){
                if(p < 2) c[p] = k;
                p++;
            }
        }
        if(2 < p) continue;
        int m = 0;
        rep(j, n){
            if(s[c[0]][j] == 'o' || s[c[1]][j] == 'o') m++;
        }
        ans = max(ans, m);
    }

    cout << ans << endl;

    return 0;
}