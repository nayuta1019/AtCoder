/**
ABC049
2019/04/25/ 解説AC
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

struct UnionFind{
    vector<int> par;

    UnionFind(int n) : par(n, -1){}

    void init(int n){
        par.assign(n, -1);
    }

    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n, k, l;
    cin >> n >> k >> l;
    UnionFind ar = UnionFind(n);
    UnionFind br = UnionFind(n);
    vector<int> res(n, 1);

    rep(i, k){
        int p, q; cin >> p >> q;
        p--; q--;
        ar.merge(p, q);
    }
    vector< pair<int, int> > city(l);
    rep(i, l){
        int r, s; cin >> r >> s;
        r--; s--;
        city[i] = pair<int, int>(r, s);
        br.merge(r, s);
    }

    map<pair<int, int>, int> m;
    rep(i, n){
        m[pair<int, int>(ar.root(i), br.root(i))]++;
    }

    rep(i, n){
        cout << m[pair<int, int>(ar.root(i), br.root(i))] << " ";
    }
    cout << endl;

    return 0;
}