/*
2019/08/21/ AC
*/
#include <bits / stdc++.h>

    using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int l = -1, ans = -1;
  rep(i, n) {
    if (a[i] < k) {
      if (l < a[i]) {
        l = a[i];
        ans = i + 1;
      }
    }
  }

  cout << ans << endl;

  return 0;
}