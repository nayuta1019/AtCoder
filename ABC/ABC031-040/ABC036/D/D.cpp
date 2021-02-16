/*
ABC036
2019/10/27/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int N;
vector<vector<int>> G;
long long dp[101010][2];

void dfs(int v, int p) {
  dp[v][0] = dp[v][1] = 1;
  for (auto nv : G[v]) {
    if (nv == p) continue;
    dfs(nv, v);
    dp[v][0] *= dp[nv][0] + dp[nv][1], dp[v][0] %= MOD;
    dp[v][1] *= dp[nv][0], dp[v][1] %= MOD;
  }
}

int main() {
  cin >> N;
  G.assign(N, vector<int>());
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(0, -1);
  cout << (dp[0][0] + dp[0][1]) % MOD << endl;

  return 0;
}