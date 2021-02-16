/*
ABC132
2019/11/25/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long memo[2020][2020];

/* べき乗(mのn乗)を計算する関数. O(logn) */
template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}
/* フェルマーの小定理を使って二項係数を計算. O(r) */
template <typename T>
T binomial(T n, T r, const T &p) {
  if (r > n - r) return binomial(n, n - r, p);
  if (memo[n][r] != 0) return memo[n][r];
  T ansMul = 1;
  T ansDiv = 1;
  for (T i = 0; i < r; i++) {
    ansMul *= (n - i);
    ansDiv *= (i + 1);
    ansMul %= p;
    ansDiv %= p;
  }
  // ansDivの逆元
  T ans = (ansMul * modpow(ansDiv, p - 2, p)) % p;
  return memo[n][r] = ans;
}

int main() {
  long long N, K;
  cin >> N >> K;

  for (long long k = 1; k <= K; k++) {
    if (N - K + 1 < k) {
      cout << 0 << endl;
    } else {
      cout << binomial(N - K + 1, k, MOD) * binomial(K - 1, k - 1, MOD) % MOD
           << endl;
    }
  }

  return 0;
}