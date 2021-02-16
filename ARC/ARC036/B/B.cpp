/*
ARC036
2020/01/31/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  h.emplace_back(1e9 + 7);
  bool f = true;
  int x = h[0], s = 1, ans = 1;
  for (int i = 0; i < n + 1; i++) {
    if (f) {
      if (x > h[i]) f = false;
      x = h[i];
    } else {
      if (x < h[i]) {
        ans = max(ans, i - s + 1);
        s = i;
        f = true;
      }
      x = h[i];
    }
    if (i == n) {
      ans = max(ans, i - s + 1);
    }
  }

  cout << ans << endl;

  return 0;
}