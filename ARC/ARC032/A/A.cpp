/*
ARC032
2020/03/28/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n) {
  if (n == 1) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  int m = n * (n + 1) / 2;
  if (is_prime(m)) {
    cout << "WANWAN" << endl;
  } else {
    cout << "BOWWOW" << endl;
  }

  return 0;
}