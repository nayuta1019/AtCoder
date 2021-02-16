#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int N, M;
int x[125], y[125];
lint dp[1 << 16];

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  dp[0] = 1;
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) continue;
      bool flag = true;
      for (int k = 0; k < M; k++) {
        if (y[k] != j) continue;
        if ((i & (1 << x[k])) == 0) flag = false;
      }
      if (flag) dp[i | (1 << j)] += dp[i];
    }
  }

  cout << dp[(1 << N) - 1] << endl;

  return 0;
}