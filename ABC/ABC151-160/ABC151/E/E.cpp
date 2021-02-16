/*
ABC151
2020/01/21/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long MOD = 1e9 + 7;

/* べき乗(mのn乗)を計算する関数. O(logn) */
template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}

llint fact[101010];
void makecomb(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i, fact[i] %= MOD;
}
llint retcomb(int n, int r) {
  if (r < 0 || r > n) return 0;
  return fact[n] * modpow(fact[r], MOD - 2, MOD) % MOD *
         modpow(fact[n - r], MOD - 2, MOD) % MOD;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  makecomb(n + 5);

  llint ans = 0;
  for (int ri = 0; ri < 2; ri++) {
    for (int i = 0; i < n; i++) {
      llint now = retcomb(i, k - 1);
      if (ri == 1) now = -now;
      ans += now * a[i] % MOD, ans %= MOD;
    }
    reverse(a.begin(), a.end());
  }

  cout << ans << endl;
  return 0;
}
