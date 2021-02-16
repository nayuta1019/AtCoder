/*
ABC039
2019/11/24/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int H, W;

void white(int x, int y, vector<vector<char>> &ans) {
  for (int i = 0; i < 8; i++) {
    int nx = x + ddx[i];
    int ny = y + ddy[i];
    if (nx < 0 || ny < 0 || W <= nx || H <= ny) continue;
    ans[ny][nx] = '.';
  }
}

void black(int x, int y, vector<vector<char>> &ans) {
  for (int i = 0; i < 8; i++) {
    int nx = x + ddx[i];
    int ny = y + ddy[i];
    if (nx < 0 || ny < 0 || W <= nx || H <= ny) continue;
    ans[ny][nx] = '#';
  }
}

int main() {
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  vector<vector<char>> ans(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> s[i][j];
    }
  }

  ans = s;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (s[y][x] == '.') {
        white(x, y, ans);
      }
    }
  }

  vector<vector<char>> check = ans;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (ans[y][x] == '#') {
        black(x, y, check);
      }
    }
  }

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (check[y][x] != s[y][x]) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }

  cout << "possible" << endl;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cout << ans[y][x];
    }
    cout << endl;
  }

  return 0;
}