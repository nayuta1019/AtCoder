/*
2020/01/29/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int main() {
  int n, x, l;
  cin >> n;
  vector<P> xl;
  for (int i = 0; i < n; i++) {
    cin >> x >> l;
    xl.emplace_back(x + l, x - l);
  }
  sort(xl.begin(), xl.end());

  int cur = -1e9, ans = 0;
  for (auto &v : xl) {
    if (cur <= v.second) {
      ans++;
      cur = v.first;
    }
  }
  cout << ans << endl;

  return 0;
}