/*
2020/02/25/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long MOD = 1e9 + 7;

// dp[決めた桁数][N未満][桁和%d]
llint dp[101010][2][222];

int main() {
  string s;
  int d, n;
  cin >> d >> s;
  n = s.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int num = s[i] - '0';
    for (int j = 0; j < 2; j++) {     // N未満かどうか
      for (int k = 0; k <= d; k++) {  // 桁和%d
        for (int l = 0; l <= (j ? 9 : num); l++) {
          dp[i + 1][j || (l < num)][(k + l) % d] += dp[i][j][k];
          dp[i + 1][j || (l < num)][(k + l) % d] %= MOD;
        }
      }
    }
  }
  llint ans = dp[n][0][0] + dp[n][1][0] % MOD;
  ans = (ans - 1 + MOD) % MOD;
  cout << ans << endl;

  return 0;
}