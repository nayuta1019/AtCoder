/*
ABC147
2019/12/14/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < 60; i++) {
    long long k = (long long)1 << i;
    long long cnt = 0;
    for (int j = 0; j < n; j++) {
      if (k & a[j]) cnt++;
    }
    long long s = 1LL << i;
    s %= MOD;
    cnt = cnt * (n - cnt) % MOD;
    ans += s * cnt % MOD;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}