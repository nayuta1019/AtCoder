/*
2019/08/06/ 解説用
*/
#include <bits/stdc++.h>

using namespace std;

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
  int N;
  cin >> N;
  vector<long long> x(N), y(N);
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

  using pint = pair<int, int>;
  using Edge = pair<long long, pint>;
  vector<Edge> edges;

  vector<int> ids(N);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int i, int j) { return x[i] < x[j]; });

  for (int i = 0; i + 1 < ids.size(); i++) {
    int u = ids[i], v = ids[i + 1];
    edges.push_back(Edge(x[v] - x[u], pint(u, v)));
  }

  sort(ids.begin(), ids.end(), [&](int i, int j) { return y[i] < y[j]; });

  for (int i = 0; i + 1 < ids.size(); i++) {
    int u = ids[i], v = ids[i + 1];
    edges.push_back(Edge(y[v] - y[u], pint(u, v)));
  }

  sort(edges.begin(), edges.end());

  UnionFind uf(N);

  long long res = 0;
  for (auto e : edges) {
    int u = e.second.first, v = e.second.second;
    long long cost = e.first;
    if (uf.issame(u, v)) continue;
    uf.merge(u, v);
    res += cost;
  }

  cout << res << endl;

  return 0;
}