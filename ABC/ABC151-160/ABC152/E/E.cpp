/*
ABC152
2020/02/11/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long MOD = 1e9 + 7;

template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}

/* nを素因数分解する */
map<long long, long long> primefactor(long long n) {
  map<long long, long long> ret;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}

int main() {
  int N;
  cin >> N;
  vector<map<llint, llint>> primes;
  vector<llint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    auto v = primefactor(A[i]);
    primes.emplace_back(v);
  }

  map<llint, llint> L;
  for (int i = 0; i < N; i++) {
    for (auto &v : primes[i]) {
      llint p = v.first;
      llint q = v.second;
      L[p] = max(L[p], q);
    }
  }

  llint lcm = 1;
  for (auto &v : L) {
    lcm *= modpow(v.first, v.second, MOD);
    lcm %= MOD;
  }

  llint ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (lcm * modpow(A[i], MOD - 2, MOD)) % MOD, ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
