/*
ARC041
2020/01/04/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, M;
int b[555][555], ans[555][555];

int main() {
  cin >> N >> M;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      char c;
      cin >> c;
      b[y][x] = c - '0';
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (b[y][x] == 0) continue;
      ans[y + 1][x] += b[y][x];
      b[y + 1][x - 1] -= b[y][x];
      b[y + 1][x + 1] -= b[y][x];
      b[y + 2][x] -= b[y][x];
      b[y][x] = 0;
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cout << ans[y][x];
    }
    cout << endl;
  }

  return 0;
}