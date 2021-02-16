/**
2018/11/24/ 解説用
**/
#include <bits/stdc++.h>

using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<ll> sum(N + 1);
  rep(i, N) sum[i + 1] = sum[i] + a[i];

  ll x = 0;
  for (int k = 50; k >= 0; k--) {
    ll y = x ^ (1LL << k);
    cout << "y = " << y << endl;
    int cnt = 0;
    for (int l = 0; l <= N; l++) {
      for (int r = l + 1; r <= N; r++) {
        ll d = sum[r] - sum[l];
        if ((d & y) == y) cnt++;
      }
    }

    if (cnt >= K) x = y;
  }

  cout << x << endl;
}