/*
2020/01/15/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

/* べき乗(mのn乗)を計算する関数. O(logn) */
template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}

int main() {
  long long n, m, p;
  cin >> n >> m >> p;

  cout << modpow(n, p, m) << endl;

  return 0;
}