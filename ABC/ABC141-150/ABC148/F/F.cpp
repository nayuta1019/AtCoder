/*
ABC148
2019/12/23/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, u, v;
vector<vector<int>> G;

void dfs(int v, int pv, int dist[]) {
  for (auto nv : G[v]) {
    if (nv == pv) continue;
    dist[nv] = dist[v] + 1;
    dfs(nv, v, dist);
  }
}

int main() {
  cin >> N >> u >> v;
  u--, v--;
  G.resize(N);
  int a, b;
  for (int i = 0; i + 1 < N; i++) {
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  int tdist[101010] = {0}, adist[101010] = {0};
  dfs(u, -1, tdist);
  dfs(v, -1, adist);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (G[i].size() != 1) continue;
    if (tdist[i] < adist[i]) {
      ans = max(ans, adist[i] - 1);
    }
  }
  cout << ans << endl;

  return 0;
}