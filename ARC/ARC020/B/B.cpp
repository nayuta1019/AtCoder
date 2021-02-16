/*
ARC020
2020/01/16/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 1e9;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      int s = 0;
      if (i == j) continue;
      for (int k = 0; k < n; k++) {
        if (k % 2) {
          if (a[k] != j) s += c;
        } else {
          if (a[k] != i) s += c;
        }
      }
      ans = min(ans, s);
    }
  }
  cout << ans << endl;

  return 0;
}