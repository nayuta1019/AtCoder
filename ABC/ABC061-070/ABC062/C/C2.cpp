/*
ABC062
2019/08/24/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long h, w;
  cin >> h >> w;

  long long res = 1e18;
  for (int i = 0; i < 2; i++) {
    swap(h, w);
    for (long long y = 1; y < h - 1; y++) {
      long long a = y * w;
      long long b = ((h - y) / 2) * w;
      long long c = ((h - y + 1) / 2) * w;
      long long smax = max({a, b, c});
      long long smin = min({a, b, c});
      res = min(res, smax - smin);
    }
  }
  for (int i = 0; i < 2; i++) {
    swap(h, w);
    for (long long y = 1; y < h; y++) {
      long long a = y * w;
      long long b = (h - y) * (w / 2);
      long long c = (h - y) * ((w + 1) / 2);
      long long smax = max({a, b, c});
      long long smin = min({a, b, c});
      res = min(res, smax - smin);
    }
  }
  cout << res << endl;

  return 0;
}