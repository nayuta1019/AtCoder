/*
ABC139
2019/12/02/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

#define NODE(x, y) ((x)*1000 + (y))

int N;
vector<int> G[1010101];
bool used[1010101];
int dp[1010101];

// トポロジカルソートされた数列
vector<int> topo;

void dfs(int u) {
  if (used[u]) return;
  used[u] = true;
  for (auto& i : G[u]) dfs(i);
  // 帰りがけ順で追加
  topo.push_back(u);
}

void tsort() {
  for (int i = 0; i < NODE(N, N); i++)
    if (!used[i]) dfs(i);
  reverse(topo.begin(), topo.end());
}

int main() {
  cin >> N;
  int a, from, to;
  int prev;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j + 1 < N; j++) {
      cin >> a;
      a--;
      from = i, to = a;
      if (to < from) swap(from, to);
      if (j != 0) {
        G[prev].emplace_back(NODE(from, to));
      }
      prev = NODE(from, to);
    }
  }

  tsort();

  memset(used, false, sizeof(used));
  for (auto& v : topo) {
    used[v] = true;
    for (auto& nv : G[v]) {
      if (used[nv]) {
        cout << -1 << endl;
        return 0;
      }
      dp[nv] = max(dp[nv], dp[v] + 1);
    }
  }

  int ans = 0;
  for (int i = 0; i < NODE(N, N); i++) ans = max(ans, dp[i]);
  cout << ans + 1 << endl;

  return 0;
}