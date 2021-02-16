/*
ARC036
2020/04/04/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  int x = t[0] + t[1];
  for (int i = 2; i < n; i++) {
    x += t[i];
    if (x < k) {
      cout << i + 1 << endl;
      return 0;
    }
    x -= t[i - 2];
  }

  cout << -1 << endl;

  return 0;
}