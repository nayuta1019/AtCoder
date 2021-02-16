/*
ABC147
2019/12/21/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const int D = 80 * 160 + 10;
const int D2 = D * 2;

int h, w;
int a[100][100];
bitset<D2> dp[90][90];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x;
      cin >> x;
      a[i][j] = abs(a[i][j] - x);
    }
  }

  dp[0][0][D - a[0][0]] = 1;
  dp[0][0][D + a[0][0]] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i) {
        dp[i][j] |= dp[i - 1][j] << a[i][j];
        dp[i][j] |= dp[i - 1][j] >> a[i][j];
      }
      if (j) {
        dp[i][j] |= dp[i][j - 1] << a[i][j];
        dp[i][j] |= dp[i][j - 1] >> a[i][j];
      }
    }
  }

  int ans = D2;
  for (int i = 0; i < D2; i++) {
    if (dp[h - 1][w - 1][i]) {
      ans = min(ans, abs(i - D));
    }
  }

  cout << ans << endl;

  return 0;
}