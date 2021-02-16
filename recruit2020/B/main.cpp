#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> A;
vector<int> ans_y, ans_x;
vector<char> ans_com;

void func(const int &pen) {
  int pen_color = 0;
  int com0 = 0, y_cnt0 = 0, x_cnt0 = 0;
  int com1 = 0, y_cnt1 = 0, x_cnt1 = N - 1;
  int com2 = 0, y_cnt2 = 0, x_cnt2 = 0;
  int com3 = 0, y_cnt3 = 0, x_cnt3 = N - 1;

  for (int i = 0; i < M; i++) {
    if (pen_color == 0) {
      if (x_cnt0 == N) {
        ans_y[i] = -1;
        continue;
      }
      if (com0 < 5) {
        ans_y[i] = 0, ans_x[i] = com0 * 5, ans_com[i] = 'R';
      } else {
        ans_y[i] = y_cnt0 * 5, ans_x[i] = x_cnt0, ans_com[i] = 'D';
        y_cnt0++;
        if (y_cnt0 >= 5) {
          y_cnt0 = 0, x_cnt0++;
        }
      }
      com0++;
    }
    if (pen_color == 1) {
      if (x_cnt1 == -1) {
        ans_y[i] = -1;
        continue;
      }
      if (com1 < 5) {
        ans_y[i] = 0, ans_x[i] = N - com1 * 5 - 1, ans_com[i] = 'L';
      } else {
        ans_y[i] = y_cnt1 * 5, ans_x[i] = x_cnt1, ans_com[i] = 'D';
        y_cnt1++;
        if (y_cnt1 >= 5) {
          y_cnt1 = 0, x_cnt1--;
        }
      }
      com1++;
    }
    if (pen_color == 2) {
      if (x_cnt2 == N) {
        ans_y[i] = -1;
        continue;
      }
      if (com2 < 5) {
        ans_y[i] = N - 1, ans_x[i] = com2 * 5, ans_com[i] = 'R';
      } else {
        ans_y[i] = N - 1 - y_cnt2 * 5, ans_x[i] = x_cnt2, ans_com[i] = 'U';
        y_cnt2++;
        if (y_cnt2 >= 5) {
          y_cnt2 = 0, x_cnt2++;
        }
      }
      com2++;
    }
    if (pen_color == 3) {
      if (x_cnt3 == -1) {
        ans_y[i] = -1;
        continue;
      }
      if (com3 < 5) {
        ans_y[i] = N - 1, ans_x[i] = N - com3 * 5 - 1, ans_com[i] = 'L';
      } else {
        ans_y[i] = N - 1 - y_cnt3 * 5, ans_x[i] = x_cnt3, ans_com[i] = 'U';
        y_cnt3++;
        if (y_cnt3 >= 5) {
          y_cnt3 = 0, x_cnt3--;
        }
      }
      com3++;
    }

    pen_color++;
    pen_color %= 4;
  }
}

void simulate() {
  // 0 : red, 1 : blue, 2 : green, 3 : yellow
  func(3);
}

void input() {
  cin >> N >> M;
  A.assign(N, vector<int>(N, 0));
  ans_y.assign(M, -2);
  ans_x.assign(M, -2);
  ans_com.assign(M, 'x');
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
}

void output() {
  for (int i = 0; i < M; i++) {
    if (ans_y[i] == -1) {
      cout << -1 << endl;
    } else {
      cout << ans_y[i] << " " << ans_x[i] << " " << ans_com[i] << endl;
    }
  }
}

int main() {
  input();
  simulate();
  output();
  return 0;
}