/*
2020/01/29/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, s, cnt = 0;
  cin >> n >> k >> s;

  for (int i = 0; i < n; i++) {
    if (cnt < k) {
      cout << s << " ";
    } else {
      if (s == 1e9) {
        cout << 1 << " ";
      } else {
        cout << s + 1 << " ";
      }
    }
    cnt++;
  }
  cout << endl;

  return 0;
}