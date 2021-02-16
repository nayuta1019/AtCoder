/*
2019/08/23/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int res = 2;
  int f = 0;
  rep(i, n - 1) {
    if (f == 0 && a[i] < a[i + 1]) f = 1;
    if (f == 0 && a[i] > a[i + 1]) f = 2;
    if (f == 1 && a[i] > a[i + 1]) {
      f = 2;
      res++;
    }
    if (f == 2 && a[i] < a[i + 1]) {
      f = 1;
      res++;
    }
  }

  if (f == 0)
    cout << 0 << endl;
  else
    cout << res << endl;

  return 0;
}