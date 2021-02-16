#include <bits/stdc++.h>

using namespace std;

int N;
int B[4];
int l[33][33], r[33][33], ans[33][33];

int main() {
  cin >> N;
  for (int i = 0; i < 3; i++) cin >> B[i];
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> l[y][x];
      ans[y][x] = l[y][x];
    }
  }
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> r[y][x];
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = y; x < N - 1; x++) {
      int now = ans[y][x];
      int flag = 1;
      for (int k = x + 1; k < N; k++) {
        now += ans[y][k];

        while (ans[y][k - 1] < r[y][k - 1] && now < B[0] && flag == 1) {
          ans[y][k - 1]++;
          now++;
        }
        while (ans[y][k] < r[y][k] && now < B[0] && flag == 1) {
          ans[y][k]++;
          now++;
        }
        if (now == B[0]) {
          flag = 2;
          k++;
          continue;
        }

        while (ans[y][k - 1] < r[y][k - 1] && now < B[1] && flag == 2) {
          ans[y][k - 1]++;
          now++;
        }
        while (ans[y][k] < r[y][k] && now < B[1] && flag == 2) {
          ans[y][k]++;
          now++;
        }
        if (now == B[1]) {
          flag = 3;
          k++;
          continue;
        }
        while (ans[y][k - 1] < r[y][k - 1] && now < B[2] && flag == 3) {
          ans[y][k - 1]++;
          now++;
        }
        while (ans[y][k] < r[y][k] && now < B[2] && flag == 3) {
          ans[y][k]++;
          now++;
        }

        if (B[2] <= now) {
          x = k;
          break;
        }
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = y; x < N; x++) {
      ans[x][y] = ans[y][x];
    }
  }
  /*
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (!(l[y][x] <= ans[y][x] && ans[y][x] <= r[y][x])) {
        cout << x << " " << y << endl;
        cout << "l = " << l[y][x] << " r = " << r[y][x] << endl;
        cout << ans[y][x] << endl;
      }
    }
  }
  */

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cout << ans[y][x] << (x != N - 1 ? " " : "");
    }
    cout << endl;
  }

  return 0;
}