/*
AGC038
2019/10/13/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int H, W, A, B;
int ans[1010][1010];

int main() {
  cin >> H >> W >> A >> B;

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (x < A && y < B) {
        ans[y][x] = 1;
      }
      if (A <= x && B <= y) {
        ans[y][x] = 1;
      }
    }
  }

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cout << ans[y][x];
    }
    cout << endl;
  }

  return 0;
}