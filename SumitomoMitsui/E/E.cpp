/*
2020/02/09/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long MOD = 1e9 + 7;

int N;
llint A[101010];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<llint> x(N + 1), y(N + 1), z(N + 1);
  for (int i = 0; i < N; i++) {
    x[i + 1] = x[i], y[i + 1] = y[i], z[i + 1] = z[i];
    if (x[i] == A[i]) {
      x[i + 1]++;
    } else if (y[i] == A[i]) {
      y[i + 1]++;
    } else if (z[i] == A[i]) {
      z[i + 1]++;
    }
  }

  llint ans = 1;
  for (int i = 0; i < N; i++) {
    llint t = 0;
    if (x[i] == A[i]) {
      t++;
    }
    if (y[i] == A[i]) {
      t++;
    }
    if (z[i] == A[i]) {
      t++;
    }
    ans *= t, ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}