/*
ABC144
2020/01/27/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

llint n, k;
vector<llint> a, f;
bool ok(llint mid, llint kk = k) {
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (a[i] * f[i] <= mid) continue;
    kk -= a[i] - mid / f[i];
    if (kk < 0) {
      flag = false;
    }
  }
  return flag;
}

int main() {
  cin >> n >> k;
  a.assign(n, 0);
  f.assign(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  llint l = -1, r = 1e18 + 10;
  while (l + 1 < r) {
    llint mid = (l + r) / 2;
    if (ok(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << l + 1 << endl;

  return 0;
}