/*
ARC030
2020/02/27/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int n, x;
int h[110];
vector<vector<int>> g;
int ans;

bool check(int v, int pv) {
  if (h[v]) return true;

  bool flag = false;
  for (auto &nv : g[v]) {
    if (pv == nv) continue;
    flag |= check(nv, v);
  }
  return flag;
}

void dfs(int v, int pv) {
  for (auto &nv : g[v]) {
    if (pv == nv) continue;
    if (!check(nv, v)) continue;
    ans++;
    dfs(nv, v);
  }
}

int main() {
  cin >> n >> x;
  x--;
  g.assign(n, vector<int>());
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  for (int i = 0; i + 1 < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(x, -1);
  cout << ans * 2 << endl;

  return 0;
}