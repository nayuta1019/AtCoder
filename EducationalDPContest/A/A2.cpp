/*
2019/08/05/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dp[101010];

int main() {
  int N, K = 2;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++) cin >> h[i];

  for (int i = 0; i < 101010; i++) dp[i] = INF;

  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j <= i + K; j++) {
      int cost = abs(h[i] - h[j]);
      dp[j] = min(dp[j], dp[i] + cost);
    }
  }

  cout << dp[N - 1] << endl;

  return 0;
}