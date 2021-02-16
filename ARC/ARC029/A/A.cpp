/*
ARC029
2020/03/24/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    sum += t[i];
  }
  sort(t.begin(), t.end());
  if (n == 1) {
    cout << t[0] << endl;
  } else if (n == 2) {
    cout << max(t[0], t[1]) << endl;
  } else {
    int ans = sum;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int x = (i == j ? t[i] : t[i] + t[j]);
        int y = sum - x;
        int z = max(x, y);
        ans = min(ans, z);
      }
    }
    cout << ans << endl;
  }

  return 0;
}