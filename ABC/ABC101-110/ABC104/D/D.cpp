/*
ABC104
2019/11/16/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
long long dp[101010][5];
string s;

int main() {
  cin >> s;
  int n = s.size();

  for (int i = n; 0 <= i; i--) {
    for (int j = 3; 0 <= j; j--) {
      if (i == n) {
        dp[i][j] = (j == 3 ? 1 : 0);
      } else {
        dp[i][j] = dp[i + 1][j] * (s[i] == '?' ? 3 : 1);
        if (j < 3 && s[i] == '?' || s[i] == "ABC"[j]) {
          dp[i][j] += dp[i + 1][j + 1];
        }
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[0][0] << endl;

  return 0;
}