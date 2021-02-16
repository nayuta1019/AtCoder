/**
ABC074
2019/05/07/ 解説AC
**/
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

    int n; cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int ans = 0;
    rep(i, n){
        if(i < n-1 && p[i] == i+1){
            swap(p[i], p[i+1]);
            ans++;
        }
        if(i == n-1 && p[i] == i+1){
            swap(p[i], p[i-1]);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}