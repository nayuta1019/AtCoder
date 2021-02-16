/**
ABC070
2019/01/19  解説AC
グラフを隣接リストで管理する。
頂点Kからすべての頂点への最短経路を前計算する。
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

const int limit = 100010;
struct edge{
    int to;
    ll cost;
};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d){
    depth[v] = d;
    for(auto &e : tree[v]){ //tree[v][i]
        if(e.to == p) continue;
        dfs(e.to, v, d + e.cost);
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int q, k;
    cin >> q >> k;
    k--;

    dfs(k, -1, 0);
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << depth[x] + depth[y] << endl;
    }

    return 0;
}