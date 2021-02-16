/*
ARC017
2020/02/01/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, ans = 0, cnt = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int x = 0;
  for (int i = 0; i < n; i++) {
    if (x < a[i] || k == 1) {
      cnt++;
      if (k <= cnt) ans++;
    } else {
      cnt = 1;
    }
    x = a[i];
  }
  cout << ans << endl;

  return 0;
}