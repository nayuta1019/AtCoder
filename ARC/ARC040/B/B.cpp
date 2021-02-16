/*
ARC040
2020/01/30/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, r;
  string s;
  cin >> n >> r >> s;
  while (!s.empty()) {
    if (s.back() == 'o')
      s.pop_back();
    else
      break;
  }
  int ans = 0;
  bool f = false;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (f) break;
    if (n <= i + r) {
      bool g = false;
      for (int j = i; j < min(n, i + r); j++) {
        if (s[j] == '.') g = true;
      }
      if (g) ans++;
      f = true;
    } else {
      if (s[i] == '.') {
        for (int j = i; j < min(n, i + r); j++) {
          s[j] = 'o';
        }
        ans += 2;
        if (i + r == n) {
          ans--;
          f = true;
        }
      } else {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}