/*
2020/01/27/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w, n, ans = 0;
  cin >> h >> w >> n;
  while (ans < n) ans += max(h, w);
  cout << ans / max(h, w) << endl;

  return 0;
}