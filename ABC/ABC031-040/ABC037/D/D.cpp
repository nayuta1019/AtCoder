/*
ABC037
2019/09/25/ 解説AC(実装は自力)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
const int MOD = (int)1e9 + 7;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int H, W;
lint a[1010][1010];
lint dp[1010][1010];

lint dfs(int x, int y) {
  if (0 < dp[y][x]) return dp[y][x];

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || W <= nx || H <= ny) continue;
    if (a[y][x] >= a[ny][nx]) continue;
    dp[y][x] += dfs(nx, ny) + 1;
    dp[y][x] %= MOD;
  }

  return dp[y][x];
}

int main() {
  scanf("%d %d", &H, &W);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      scanf("%lld", &a[y][x]);
    }
  }

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      dfs(x, y);
    }
  }

  lint res = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      res += dp[y][x] + 1;
      res %= MOD;
    }
  }

  printf("%lld\n", res);

  return 0;
}