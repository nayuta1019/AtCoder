/*
2019/11/27/ 解説AC
*/
#include <iostream>
#include <vector>

using namespace std;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int N;
  long long W;
  cin >> N >> W;
  vector<long long> w(N);
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  const long long INF = 1e18;
  vector<vector<long long>> dp(N + 1, vector<long long>(101010, INF));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 101010; j++) {
      if (0 <= j - v[i]) {
        chmin(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
      }
      chmin(dp[i + 1][j], dp[i][j]);
    }
  }

  int ans;
  for (int i = 0; i < 101010; i++) {
    if (dp[N][i] <= W) ans = i;
  }

  cout << ans << endl;

  return 0;
}