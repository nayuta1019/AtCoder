/*
ARC032
2019/12/16/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> G;
bool used[101010];

void dfs(int v, int pv) {
  used[v] = true;
  for (auto nv : G[v]) {
    if (nv == pv) continue;
    if (used[nv]) continue;
    dfs(nv, v);
  }
}

int main() {
  cin >> N >> M;
  G.assign(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (used[i]) continue;
    dfs(i, -1);
    ans++;
  }

  cout << ans - 1 << endl;

  return 0;
}