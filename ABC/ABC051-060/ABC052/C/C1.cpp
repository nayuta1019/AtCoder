/*
ABC052
2019/07/13/ AC
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<bool> primes(n + 1, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = false;
      }
    }
  }

  long long ans = 1;
  for (int i = 0; i <= n; i++) {
    if (!primes[i]) continue;

    long long cnt = 0;
    for (int j = i; j <= n; j++) {
      int tmp = j;
      while (tmp != 0 && tmp % i == 0) {
        tmp /= i;
        cnt++;
      }
    }
    ans *= cnt + 1;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}