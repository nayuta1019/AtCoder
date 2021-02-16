/*
ABC133
2019/08/15/ 解説AC
*/
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int N, K;
vector<vector<int>> G;
long long res = 1;

void dfs(int cur, int pre, int num) {
  res = res * num % MOD;
  num = K - 1;
  if (pre != -1) num--;

  for (auto e : G[cur]) {
    if (e == pre) continue;
    dfs(e, cur, num);
    num--;
  }
}

int main() {
  cin >> N >> K;
  G.assign(N, vector<int>());
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(0, -1, K);

  cout << res << endl;

  return 0;
}