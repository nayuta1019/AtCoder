#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;
  vector<int> v(k + 1);
  v[1] = 7 % k;
  for (int i = 2; i <= k; i++) {
    v[i] = (v[i - 1] * 10 + 7) % k;
  }
  for (int i = 1; i <= k; i++) {
    if (v[i] == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}