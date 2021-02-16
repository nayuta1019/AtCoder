/*
ABC129
2020/02/24/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long llint;

// dp[決めた桁数][N未満]
llint dp[101010][2];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    // a + b = 0
    if (d == 0) {
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
    } else {
      dp[i + 1][1] += dp[i][0] + dp[i][1];
    }
    dp[i + 1][0] %= MOD;
    dp[i + 1][1] %= MOD;
    // a + b = 1
    if (d == 0) {
      dp[i + 1][1] += dp[i][1] * 2;
    } else {
      dp[i + 1][0] += dp[i][0] * 2;
      dp[i + 1][1] += dp[i][1] * 2;
    }
    dp[i + 1][0] %= MOD;
    dp[i + 1][1] %= MOD;
  }
  cout << (dp[n][0] + dp[n][1]) % MOD << endl;

  return 0;
}