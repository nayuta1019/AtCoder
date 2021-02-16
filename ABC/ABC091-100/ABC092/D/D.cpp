/*
ABC092
2019/08/24/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, b;
  cin >> a >> b;

  int k = 50;
  char grid[110][110];
  rep(y, 2 * k) rep(x, 2 * k) {
    if (y < k)
      grid[y][x] = '#';
    else
      grid[y][x] = '.';
  }

  for (int y = 0; y < k - 1; y += 2) {
    for (int x = 0; x < 2 * k; x += 2) {
      if (a <= 1) continue;
      grid[y][x] = '.';
      a--;
    }
  }

  for (int y = k + 1; y < 2 * k - 1; y += 2) {
    for (int x = 0; x < 2 * k; x += 2) {
      if (b <= 1) continue;
      grid[y][x] = '#';
      b--;
    }
  }

  cout << 2 * k << " " << 2 * k << endl;
  rep(y, 2 * k) {
    rep(x, 2 * k) cout << grid[y][x];
    cout << endl;
  }

  return 0;
}