/*
ABC145
2019/11/27/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> AB(N);
  for (int i = 0; i < N; i++) {
    cin >> AB[i].first >> AB[i].second;
  }
  sort(AB.begin(), AB.end());
  vector<int> dp(T + 1, 0);

  for (auto& p : AB) {
    for (int k = T - 1; 0 <= k; k--) {
      chmax(dp[min(T, k + p.first)], dp[k] + p.second);
    }
  }

  cout << dp.back() << endl;

  return 0;
}