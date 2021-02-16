/*
ARC037
2019/08/30/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  lint N, K;
  cin >> N >> K;
  vector<lint> a(N), b(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  lint l = 0, r = 2e18, tmp = 0;
  while (r - l > 1) {
    lint mid = (r + l + 1) / 2;
    tmp = 0;
    for (int i = 0; i < N; i++) {
      lint h = mid / a[i];
      tmp += upper_bound(b.begin(), b.end(), h) - b.begin();
    }
    if (tmp < K) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << r << endl;

  return 0;
}