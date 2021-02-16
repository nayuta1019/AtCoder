/**
ABC049
2019/04/25/ 未完成
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

    int n, k, l;
    cin >> n >> k >> l;
    vector< vector<int> > city(n+1);

    

    rep(i, k){
        int p, q;
        cin >> p >> q;
        city[p].push_back(q);
        city[q].push_back(p);
    }
    rep(i, l){
        int r, s;
        cin >> r >> s;
        city[r].push_back(s);
        city[s].push_back(r);
    }

    rep(i, n+1) sort(city[i].begin(), city[i].end());

    FOR(i, 1, n+1){
        int ans = 0;
        rep(j, city[i].size()){
            if( city[i][j] == city[i][j+1] && j+1 < city.size() ){
                ans++;
            }
        }
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}