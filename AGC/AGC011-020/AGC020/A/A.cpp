/*
AGC020
2019/08/26/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b;
  cin >> n >> a >> b;

  if ((b - a - 1) % 2) {
    cout << "Alice\n";
  } else {
    cout << "Borys\n";
  }
  return 0;
}