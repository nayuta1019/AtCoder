/*
ARC004
2020/04/08/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  sort(d.rbegin(), d.rend());
  int t = 0;
  for (int i = 1; i < n; i++) {
    t += d[i];
  }
  cout << d[0] + t << endl;
  if (d[0] <= t) {
    cout << 0 << endl;
  } else {
    cout << d[0] - t << endl;
  }

  return 0;
}