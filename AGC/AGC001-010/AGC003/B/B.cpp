/*
AGC003
2020/03/01/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  int n;
  cin >> n;
  vector<llint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  llint ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ans += sum / 2;
      sum = 0;
    }
    sum += a[i];
  }
  ans += sum / 2;
  cout << ans << endl;

  return 0;
}