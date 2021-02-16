/*
ABC129
2019/12/08/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;

int dp[101010][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    // a + b = 0
    if (s[i] == '0') {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
    } else {
      dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;
    }

    // a + b = 1
    if (s[i] == '0') {
      dp[i + 1][1] += dp[i][1] * 2 % MOD, dp[i + 1][1] %= MOD;
    } else {
      dp[i + 1][0] += dp[i][0] * 2 % MOD, dp[i + 1][0] %= MOD;
      dp[i + 1][1] += dp[i][1] * 2 % MOD, dp[i + 1][1] %= MOD;
    }
  }

  int ans = (dp[n][0] + dp[n][1]) % MOD;
  cout << ans << endl;

  return 0;
}