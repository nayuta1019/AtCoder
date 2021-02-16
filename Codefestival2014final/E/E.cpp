/*
2020/03/29/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }
  if (n < 3) {
    cout << 0 << endl;
    return 0;
  }
  int cur = r[1], ans = 2, j = 2;
  bool flag = (r[0] < r[1]);
  for (int i = 0; i + 1 < n; i++) {
    if (r[i] != r[i + 1]) {
      cur = r[i + 1];
      flag = (r[i] < r[i + 1]);
      break;
    }
    j++;
  }

  for (int i = j; i < n; i++) {
    if (flag) {
      if (cur > r[i]) {
        ans++;
        flag = !flag;
      }
    } else {
      if (cur < r[i]) {
        ans++;
        flag = !flag;
      }
    }
    cur = r[i];
  }
  if (ans == 2) ans = 0;
  cout << ans << endl;

  return 0;
}