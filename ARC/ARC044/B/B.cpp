/*
ARC044
2019/11/16/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}

long long MOD = 1e9 + 7;
int N;
long long a[101010], cnt[101010], d = 0;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (i == 0 && a[i] != 0) {
      cout << 0 << endl;
      return 0;
    }
    if (i != 0 && a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
    cnt[a[i]]++;
    d = max(d, a[i]);
  }
  long long ans = 1;
  for (int i = 1; i <= d; i++) {
    ans *= modpow(2LL, cnt[i] * (cnt[i] - 1) / 2, MOD);
    ans %= MOD;
    long long tmp = modpow(2LL, cnt[i - 1], MOD) - 1;
    ans *= modpow(tmp, cnt[i], MOD);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
