/*
2020/01/17/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  llint n, k;
  cin >> n >> k;
  vector<llint> a(n), sum(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];

  llint x = 0;
  for (int i = 50; 0 <= i; i--) {
    llint y = x | (1LL << i);
    int cnt = 0;
    for (int l = 0; l <= n; l++) {
      for (int r = l + 1; r <= n; r++) {
        llint d = sum[r] - sum[l];
        if ((d & y) == y) cnt++;
      }
    }
    if (k <= cnt) x = y;
  }
  cout << x << endl;

  return 0;
}