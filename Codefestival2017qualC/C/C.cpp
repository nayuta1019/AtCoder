/*
2020/01/01/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  string t = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'x') {
      t += s[i];
    }
  }

  int n = t.size();
  bool ok = true;
  for (int i = 0; i < n / 2; i++) {
    if (t[i] != t[n - i - 1]) ok = false;
  }

  if (ok) {
    int l = 0, r = (int)s.size() - 1, ans = 0;
    while (l < r) {
      if (s[l] == 'x') {
        if (s[r] != 'x')
          l++, ans++;
        else
          l++, r--;
      } else {
        if (s[r] == 'x')
          r--, ans++;
        else
          l++, r--;
      }
    }
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}