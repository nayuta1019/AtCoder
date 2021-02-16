/**
2019/05/07/ 自力AC
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

int imos[1000001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;

    rep(i, n){
        int s, t; cin >> s >> t;
        imos[s] += 1;
        imos[t] -= 1;
    }

    rep(i, 1000001){
        imos[i+1] += imos[i];
    }

    int ans = 0;
    bool st = true;
    rep(i, 1000001){
        if(0 < imos[i]){
            if(st) ans++, st = false;
        }else{
            st = true;
        }
    }

    cout << ans << endl;

    return 0;
}