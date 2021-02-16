/*
ABC149
2020/01/06/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

/* エラトステネスの篩 */
vector<int> sieve_of_eratosthenes(int n) {
  vector<int> primes(n + 1, 0);

  for (int i = 2; i <= n; i++) primes[i] = i;

  for (int i = 2; i * i <= n; i++) {
    if (0 == primes[i]) continue;  //  0ならば素数ではない
    for (int j = i + i; j <= n; j += i) primes[j] = 0;  //  iの倍数を0にする
  }

  // primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());

  return primes;
}

int main() {
  int x;
  cin >> x;

  auto v = sieve_of_eratosthenes(1000000);
  for (auto w : v) {
    if (w != 0) {
      if (x <= w) {
        cout << w << endl;
        return 0;
      }
    }
  }

  return 0;
}