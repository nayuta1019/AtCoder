/*
ARC044
2020/02/05/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

/* 素数かどうか判定. 素数 => true */
bool is_prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "Not Prime" << endl;
    return 0;
  }

  if (is_prime(n)) {
    cout << "Prime" << endl;
    return 0;
  }
  int sum = 0;
  if (n % 10 != 5 && n % 10 % 2 != 0) {
    while (n != 0) sum += n % 10, n /= 10;
    if (!(sum % 3 == 0)) {
      cout << "Prime" << endl;
      return 0;
    }
  }
  cout << "Not Prime" << endl;

  return 0;
}