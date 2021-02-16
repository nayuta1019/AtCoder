/*
ABC129
2019/11/25/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int H, W;
char s[2020][2020];
int h[2020][2020];
int w[2020][2020];

int main() {
  cin >> H >> W;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> s[y][x];
    }
  }

  int cnt = 0;
  for (int y = 0; y < H; y++) {
    cnt = 0;
    for (int x = 0; x < W; x++) {
      if (s[y][x] == '#') {
        cnt = 0;
        continue;
      }
      cnt++;
      w[y][x] = cnt;
    }
    cnt = 0;
    for (int x = W - 1; 0 <= x; x--) {
      if (s[y][x] == '#') {
        cnt = 0;
        continue;
      }
      cnt = max(cnt, w[y][x]);
      w[y][x] = cnt;
    }
  }

  for (int x = 0; x < W; x++) {
    cnt = 0;
    for (int y = 0; y < H; y++) {
      if (s[y][x] == '#') {
        cnt = 0;
        continue;
      }
      cnt++;
      h[y][x] = cnt;
    }
    cnt = 0;
    for (int y = H - 1; 0 <= y; y--) {
      if (s[y][x] == '#') {
        cnt = 0;
        continue;
      }
      cnt = max(cnt, h[y][x]);
      h[y][x] = cnt;
    }
  }

  int ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      ans = max(ans, h[y][x] + w[y][x] - 1);
    }
  }

  cout << ans << endl;

  return 0;
}