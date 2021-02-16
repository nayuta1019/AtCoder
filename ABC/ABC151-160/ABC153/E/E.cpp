/*
ABC153
2020/02/03/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int dp[1010][20202];

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < 1010; i++) {
    for (int j = 0; j < 20202; j++) {
      dp[i][j] = 1 << 29;
    }
  }
  for (int i = 0; i <= n; i++) dp[i][0] = 0;

  int amax = *max_element(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= h + amax; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (a[i] <= j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j - a[i]] + b[i]);
      }
    }
  }

  int ans = 1 << 29;
  for (int i = h; i <= h + amax; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans << endl;

  return 0;
}