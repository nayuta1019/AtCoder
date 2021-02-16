/*
ABC161
2020/04/06/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;
  vector<int> l, r;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x') continue;
    l.emplace_back(i + 1);
    i += c;
  }

  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x') continue;
    r.emplace_back(n - i);
    i += c;
  }
  reverse(r.begin(), r.end());

  if (r.size() > k) {
    return 0;
  }
  for (int i = 0; i < r.size(); i++) {
    if (r[i] == l[i]) {
      cout << r[i] << endl;
    }
  }

  return 0;
}