/*
2019/11/20/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, M;
char masu[2020][2020];
int ans[2020][2020][5];  // u r d l

int main() {
  cin >> N >> M;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> masu[y][x];
    }
  }

  int cnt = 0;
  for (int y = 0; y < N; y++) {
    cnt = 0;
    for (int x = 0; x < M; x++) {
      if (masu[y][x] == '.') {
        ans[y][x][3] = cnt;
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }
  for (int y = N - 1; 0 <= y; y--) {
    cnt = 0;
    for (int x = M - 1; 0 <= x; x--) {
      if (masu[y][x] == '.') {
        ans[y][x][1] = cnt;
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }
  for (int x = 0; x < M; x++) {
    cnt = 0;
    for (int y = 0; y < N; y++) {
      if (masu[y][x] == '.') {
        ans[y][x][0] = cnt;
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }
  for (int x = M - 1; 0 <= x; x--) {
    cnt = 0;
    for (int y = N - 1; 0 <= y; y--) {
      if (masu[y][x] == '.') {
        ans[y][x][2] = cnt;
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }

  long long res = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      res += (ans[y][x][0] + ans[y][x][2]) * (ans[y][x][1] + ans[y][x][3]);
    }
  }
  cout << res << endl;

  return 0;
}