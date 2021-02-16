#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int N, M;
vector<vector<int>> g;
vector<bool> used;
vector<P> ts;  // depth, par

void dfs(int v, int d) {
  if (used[v]) {
    ts[v] = {max(ts[v].first, d), v};
    return;
  }
  used[v] = true;
  for (auto &nv : g[v]) {
    dfs(nv, d + 1);
  }
  ts[v] = {d, v};
}

void tsort(int r) {
  // for (int i = 0; i < N; i++) dfs(i, 0);
  dfs(r, 0);
  // reverse(ts.begin(), ts.end());
}

int main() {
  cin >> N >> M;
  g.assign(N, vector<int>());
  ts.assign(N, P());
  used.assign(N, false);
  vector<int> in(N, 0);
  for (int i = 0; i < N + M - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    in[b]++;
  }
  int r;
  for (int i = 0; i < N; i++) {
    if (in[i] == 0) r = i;
  }

  tsort(r);
  sort(ts.begin(), ts.end());
  vector<int> ans(N, 0);
  int d = -1, par = -1;
  for (int i = 0; i < N; i++) {
    if (ts[i].first - d > 1) {
      d++;
      par = ts[i - 1].second;
    }
    ans[ts[i].second] = par;
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] + 1 << endl;
  }

  return 0;
}