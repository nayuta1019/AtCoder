/*
ARC035
2020/01/07/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long func(long long x) {
  long long ret = 1;
  for (long long i = 1; i <= x; i++) ret *= i, ret %= MOD;
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<long long> t(n);
  map<long long, long long> mp;
  for (int i = 0; i < n; i++) cin >> t[i], mp[t[i]]++;
  sort(t.begin(), t.end());
  vector<long long> r(n, 0);
  r[0] = t[0];
  for (int i = 1; i < n; i++) r[i] = t[i] + r[i - 1];
  long long ans = 1, sum = 0;
  for (auto x : mp) {
    ans *= func(x.second);
    ans %= MOD;
  }
  for (auto x : r) sum += x;
  cout << sum << endl;
  cout << ans << endl;

  return 0;
}