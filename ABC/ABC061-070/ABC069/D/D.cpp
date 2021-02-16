/**
ABC069
2019/05/04/ 自力AC
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

    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector< vector<int> > ans(h, vector<int>(w));
    
    int k = 0, l = 0;
    rep(i, n){
        rep(j, a[i]){
            ans[k][l] = i+1;
            l++;
            if(l == w){
                k++;
                l = 0;
            }
        }
    }

    for(int i = 1; i < h; i+=2){
        reverse(all(ans[i]));
    }
    
    rep(i, h){
        rep(j, w){
            cout << ans[i][j] << (j != w-1 ? " " : "");
        }
        cout << endl;
    }

    return 0;
}