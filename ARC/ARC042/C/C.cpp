/*
ARC042
2020/02/03/ 解説AC(自力実装)
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int dp[5555][5555];

int main() {
  int n, p;
  cin >> n >> p;
  vector<P> ab;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ab.emplace_back(a, b);
  }
  sort(ab.rbegin(), ab.rend());

  int pp = p;

  for (int i = 0; i < n; i++) {
    for (int v = 0; v <= p; v++) {
      int w = v - ab[i].first;
      if (0 <= w) {
        if (dp[i + 1][v] < dp[i][w] + ab[i].second) {
          dp[i + 1][v] = dp[i][w] + ab[i].second;
        }
      }
      if (dp[i + 1][v] < dp[i][v]) {
        dp[i + 1][v] = dp[i][v];
      }
    }
  }

  reverse(ab.begin(), ab.end());
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    // cout << "i = " << i << " " << dp[i][p] << endl;
    for (int j = 0; j < n - i; j++) {
      ans = max(ans, dp[i][p] + ab[j].second);
      // cout << dp[i][p] << " + " << ab[j].second << endl;
    }
  }
  cout << ans << endl;

  return 0;
}