/*
2019/08/31/ AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, t;
  cin >> a >> b >> t;

  int tmp = b - a;
  while (true) {
    b += tmp;
    if (t <= b) {
      cout << b << endl;
      break;
    }
  }

  return 0;
}