/*
ABC067
2019/12/23/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

void dfs(int v, int pv, int dist[]) {
  for (auto nv : G[v]) {
    if (nv == pv) continue;
    dist[nv] = dist[v] + 1;
    dfs(nv, v, dist);
  }
}

int main() {
  cin >> N;
  G.resize(N);
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  int f[101010] = {0}, s[101010] = {0};
  dfs(0, -1, f);
  dfs(N - 1, -1, s);
  int fc = 0, sc = 0;
  for (int i = 0; i < N; i++) {
    if (f[i] <= s[i])
      fc++;
    else
      sc++;
  }
  if (fc > sc) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }

  return 0;
}