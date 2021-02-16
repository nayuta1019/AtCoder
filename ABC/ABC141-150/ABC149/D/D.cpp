/*
ABC149
2020/01/13/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;

  string m = "";
  for (int i = 0; i < n; i++) {
    int j = i - k;
    if (j < 0) {
      if (t[i] == 'r') m += 'p';
      if (t[i] == 's') m += 'r';
      if (t[i] == 'p') m += 's';
      continue;
    }
    if (t[i] == t[j]) {
      if (t[i] == 'r') {
        if (m[j] == 'p')
          m += 'r';
        else
          m += 'p';
      }
      if (t[i] == 's') {
        if (m[j] == 'r')
          m += 's';
        else
          m += 'r';
      }
      if (t[i] == 'p') {
        if (m[j] == 's')
          m += 'p';
        else
          m += 's';
      }
    } else {
      if (t[i] == 'r') m += 'p';
      if (t[i] == 's') m += 'r';
      if (t[i] == 'p') m += 's';
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] != m[i]) {
      if (t[i] == 'r') ans += p;
      if (t[i] == 's') ans += r;
      if (t[i] == 'p') ans += s;
    }
  }

  cout << ans << endl;

  return 0;
}