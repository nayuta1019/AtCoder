/*
AGC021
2019/08/27/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;

  int res = 0;
  while (9 < n) {
    long long tmp = n % 10;
    n /= 10;
    if (tmp < 9) {
      tmp = 9;
      n--;
    }
    res += tmp;
  }

  res += n;

  cout << res << endl;

  return 0;
}