/*
ARC048
2019/12/17/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int x[101010][3];

int main() {
  int N;
  cin >> N;
  vector<tuple<int, int, int>> info;
  for (int i = 0; i < N; i++) {
    int r, h;
    cin >> r >> h;
    h--;
    info.emplace_back(r, h, i);
    x[r][h]++;
  }
  sort(info.rbegin(), info.rend());

  int r, h, id, p = -1, sum = 0, tmp = 0;
  int w = 0, l = 0, d = 0;
  vector<tuple<int, int, int, int>> ans;
  for (int i = 0; i < N; i++) {
    tie(r, h, id) = info[i];

    if (p != r) {
      sum += tmp, tmp = 0, p = r;
    }
    tmp++;
    w = N - sum - x[r][0] - x[r][1] - x[r][2] + x[r][(h + 1) % 3];
    l = sum + x[r][(h + 2) % 3];
    d = x[r][h] - 1;
    ans.emplace_back(id, w, l, d);
  }

  sort(ans.begin(), ans.end());
  for (int i = 0; i < N; i++) {
    tie(id, w, l, d) = ans[i];
    cout << w << " " << l << " " << d << endl;
  }

  return 0;
}