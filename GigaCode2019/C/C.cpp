/*
2019/12/12/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
  int D;
  cin >> D;
  vector<long long> a(D), b(D);
  for (int i = 0; i < D; i++) cin >> a[i];
  for (int i = 0; i < D; i++) cin >> b[i];

  long long sum = 0, ans = INF;
  for (int i = 0; i < D; i++) {
    sum += a[i];
    if (b[i] <= sum) {
      ans = min(ans, b[i]);
    }
  }

  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}