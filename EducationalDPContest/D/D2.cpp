/*
2019/11/27/ 解説AC
*/
#include <iostream>
#include <vector>

using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  long long W;
  cin >> N >> W;
  vector<int> w(N);
  vector<long long> v(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (0 <= j - w[i]) {
        chmax(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
      }
      chmax(dp[i + 1][j], dp[i][j]);
    }
  }

  cout << dp[N][W] << endl;

  return 0;
}