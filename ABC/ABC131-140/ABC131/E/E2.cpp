/*
ABC131
2019/12/23/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int main() {
  int n, k;
  cin >> n >> k;

  int cnt = (n - 1) * (n - 2) / 2 - k;
  if (cnt < 0) {
    cout << -1 << endl;
    return 0;
  }

  vector<P> ans;
  for (int i = 0; i + 1 < n; i++) {
    ans.emplace_back(1, i + 2);
  }

  for (int i = 2; i + 1 <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (cnt == 0) continue;
      cnt--;
      ans.emplace_back(i, j);
    }
  }

  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}