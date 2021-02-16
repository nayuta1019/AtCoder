/**
ABC126
2019/06/01/ 解説AC
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}

  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> X(M), Y(M), Z(M);
  rep(i, M) {
    cin >> X[i] >> Y[i] >> Z[i];
    X[i]--;
    Y[i]--;
  }
  UnionFind uf(N);
  rep(i, M) uf.merge(X[i], Y[i]);
  set<int> se;
  rep(i, N) se.insert(uf.root(i));
  cout << (int)se.size() << endl;

  return 0;
}