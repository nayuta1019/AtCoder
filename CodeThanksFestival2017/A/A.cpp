/*
2019/10/30/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int ans = 0, t;
  for (int i = 0; i < 8; i++) {
    cin >> t;
    ans = max(ans, t);
  }
  cout << ans << endl;
  return 0;
}