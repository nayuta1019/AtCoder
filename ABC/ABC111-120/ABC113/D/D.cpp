/*
ABC113
2020/02/26/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

// dp[決まった段数][どの列にいるか]
int dp[110][10];

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  k--;
  dp[0][0] = 1;

  for (int y = 0; y < h; y++) {
    for (int bit = 0; bit < (1 << (w - 1)); bit++) {
      bool ng = false;
      for (int i = 0; i + 2 < w; i++) {
        if ((bit >> i) % 4 == 3) ng = true;
      }
      if (ng) continue;
      vector<int> id(w);
      for (int i = 0; i < w; i++) {
        id[i] = i;
      }
      for (int i = 0; i + 1 < w; i++) {
        if (bit >> i & 1) swap(id[i], id[i + 1]);
      }
      for (int i = 0; i < w; i++) {
        dp[y + 1][id[i]] += dp[y][i];
        dp[y + 1][id[i]] %= MOD;
      }
    }
  }
  cout << dp[h][k] << endl;

  return 0;
}