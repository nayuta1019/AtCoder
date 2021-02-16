/*
ABC128
2020/02/18/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef tuple<llint, llint, llint> TP;

int main() {
  int n, q;
  cin >> n >> q;
  vector<TP> v;
  for (int i = 0; i < n; i++) {
    llint s, t, x;
    cin >> s >> t >> x;
    v.emplace_back(s - x, 0, x);
    v.emplace_back(t - x, 1, x);
  }

  for (int i = 0; i < q; i++) {
    llint d;
    cin >> d;
    v.emplace_back(d, 2, i);
  }
  sort(v.begin(), v.end());

  vector<llint> ans(q);
  multiset<llint> se;
  for (auto &w : v) {
    llint s, k, x;
    tie(s, k, x) = w;
    if (k == 0) {
      se.insert(x);
    } else if (k == 1) {
      se.erase(se.lower_bound(x));
    } else {
      ans[x] = (se.empty() ? -1 : *se.begin());
    }
  }

  for (auto &w : ans) {
    cout << w << endl;
  }

  return 0;
}