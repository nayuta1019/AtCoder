/*
ARC057
2020/02/06/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

const llint m = 2000000000000;

int main() {
  llint n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << m - n << endl;
  } else {
    llint ans = 0;
    while (n < m) {
      n += 1 + k * n;
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}