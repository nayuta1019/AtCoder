/*
ABC154
2020/02/16/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t, u;
  int a, b;
  cin >> s >> t;
  cin >> a >> b;
  cin >> u;

  if (s == u) {
    cout << max(a - 1, 0) << " " << b << endl;
  } else {
    cout << a << " " << max(b - 1, 0) << endl;
  }

  return 0;
}