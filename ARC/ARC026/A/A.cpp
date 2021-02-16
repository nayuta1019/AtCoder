/*
ARC026
2020/03/16/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  ans += min(n, 5) * b;
  n = max(0, n - 5);
  ans += n * a;
  cout << ans << endl;

  return 0;
}