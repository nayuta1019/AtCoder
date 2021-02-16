/*
2019/11/03/
*/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int N;
vector<vector<int>> G;
long long f[101010], g[101010];

void dfs(int v, int p) {
  f[v] = 1, g[v] = 1;
  for (auto nv : G[v]) {
    if (nv == p) continue;
    dfs(nv, v);
    f[v] *= f[nv] + g[nv];
    g[v] *= f[nv];
    f[v] %= MOD, g[v] %= MOD;
  }
}

int main() {
  cin >> N;
  G.assign(N, vector<int>());
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(0, -1);
  cout << (f[0] + g[0]) % MOD << endl;

  return 0;
}