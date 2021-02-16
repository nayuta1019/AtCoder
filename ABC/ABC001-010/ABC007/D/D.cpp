/*
ABC007
2020/02/28/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

// dp[決めた桁数][N未満][4と9を含む]
llint dp1[20][2][2];
llint dp2[20][2][2];

int main() {
  llint x, y;
  cin >> x >> y;
  x--;
  string a, b;
  a = to_string(x);
  b = to_string(y);

  llint ans = 0;
  dp1[0][0][0] = 1, dp2[0][0][0] = 1;
  int n = b.size();
  for (int i = 0; i < n; i++) {
    int num = b[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l <= (j ? 9 : num); l++) {
          dp1[i + 1][j || (l < num)][k || (l == 4 || l == 9)] += dp1[i][j][k];
        }
      }
    }
  }
  ans += dp1[n][0][1] + dp1[n][1][1];
  int m = a.size();
  for (int i = 0; i < m; i++) {
    int num = a[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l <= (j ? 9 : num); l++) {
          dp2[i + 1][j || (l < num)][k || (l == 4 || l == 9)] += dp2[i][j][k];
        }
      }
    }
  }
  ans -= dp2[m][0][1] + dp2[m][1][1];
  cout << ans << endl;

  return 0;
}