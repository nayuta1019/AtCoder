/**
ABC089
2019/05/13/ 解説AC
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

    int H, W, D, Q;
    int dist[99000];
    map<int, pair<int, int>> mp;
    cin >> H >> W >> D;
    rep(y, H){
        rep(x, W){
            int A;
            cin >> A;
            mp[A] = make_pair(x+1, y+1);
        }
    }

    FOR(i, D+1, H*W+1){
        dist[i] = dist[i-D] + abs(mp[i].first - mp[i-D].first) + abs(mp[i].second - mp[i-D].second);
    }

    cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        cout << dist[R] - dist[L] << "\n";
    }

    return 0;
}