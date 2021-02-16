/**
AGC033
2019/05/05/ 解説用
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  int sr, sc;
  cin >> sr >> sc;
  sr--, sc--;
  string s, t;
  cin >> s >> t;

  int now;
  bool ans = true;

  now = sc;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') now--;
    if (now < 0) ans = false;
    if (t[i] == 'R') now = min(now + 1, w - 1);
  }

  now = sc;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') now++;
    if (w <= now) ans = false;
    if (t[i] == 'L') now = max(now - 1, 0);
  }

  now = sr;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') now--;
    if (now < 0) ans = false;
    if (t[i] == 'D') now = min(now + 1, h - 1);
  }

  now = sr;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') now++;
    if (h <= now) ans = false;
    if (t[i] == 'U') now = max(now - 1, 0);
  }
  
  cout << ((ans) ? "YES" : "NO") << endl;
}
