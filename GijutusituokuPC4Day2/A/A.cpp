/*
2019/12/14/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (y % 2 || y < 0) {
    cout << -1 << endl;
    return 0;
  }

  int t = y / 2;
  x = abs(x);
  if (x > t) {
    cout << -1 << endl;
  } else {
    if (t % 2) {
      if (x % 2 == 1)
        cout << t << endl;
      else
        cout << -1 << endl;
    } else {
      if (x % 2 == 0)
        cout << t << endl;
      else
        cout << -1 << endl;
    }
  }

  return 0;
}