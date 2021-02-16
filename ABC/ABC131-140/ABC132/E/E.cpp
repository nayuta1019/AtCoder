/*
ABC132
2019/12/28/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
const int INF = 1e9;

int n, m, s, t;
vector<vector<int>> g;
int dist[101010][3];

int main() {
  cin >> n >> m;
  g.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
  }
  cin >> s >> t;
  s--, t--;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      dist[i][j] = INF;
    }
  }
  queue<P> q;
  q.push(P(s, 0));
  dist[s][0] = 0;
  while (!q.empty()) {
    int v = q.front().first;
    int l = q.front().second;
    q.pop();
    for (auto nv : g[v]) {
      int nl = (l + 1) % 3;
      if (dist[nv][nl] != INF) continue;
      dist[nv][nl] = dist[v][l] + 1;
      q.push(P(nv, nl));
    }
  }
  int ans = dist[t][0];
  if (ans == INF)
    ans = -1;
  else
    ans /= 3;
  cout << ans << endl;

  return 0;
}