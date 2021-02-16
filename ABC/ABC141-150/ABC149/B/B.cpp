/*
ABC149
2020/01/03/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, k, t;
  cin >> a >> b >> k;
  t = max(0LL, k - a);
  a = max(0LL, a - k);
  b = max(0LL, b - t);

  cout << a << " " << b << endl;

  return 0;
}