/*
2019/08/03/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

//
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
//

const long long INF = 1LL << 60;

int N, M;
vector<vector<int> > G;

int dp[100100];
int rec(int v) {
  if (dp[v] != -1) return dp[v];

  int res = 0;
  for (auto nv : G[v]) {
    chmax(res, rec(nv) + 1);
  }

  return dp[v] = res;
}

int main() {
  cin >> N >> M;
  G.assign(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
  }

  for (int i = 0; i < N; i++) dp[i] = -1;

  int res = 0;
  for (int v = 0; v < N; v++) chmax(res, rec(v));

  cout << res << endl;

  return 0;
}