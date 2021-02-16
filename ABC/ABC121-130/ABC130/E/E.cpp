/*
ABC130
2020/02/12/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long MOD = 1e9 + 7;

llint dp[2020][2020];

int main() {
  int n, m;
  cin >> n >> m;
  vector<llint> s(n), t(m);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i - 1 >= 0 && j - 1 >= 0 && s[i - 1] == t[j - 1]) {
        dp[i][j] += dp[i - 1][j - 1], dp[i][j] %= MOD;
      }
      if (i - 1 >= 0) dp[i][j] += dp[i - 1][j], dp[i][j] %= MOD;
      if (j - 1 >= 0) dp[i][j] += dp[i][j - 1], dp[i][j] %= MOD;
      if (i - 1 >= 0 && j - 1 >= 0) {
        dp[i][j] -= dp[i - 1][j - 1];
        if (dp[i][j] < 0) dp[i][j] += MOD;
      }
    }
  }
  cout << dp[n][m] << endl;

  return 0;
}