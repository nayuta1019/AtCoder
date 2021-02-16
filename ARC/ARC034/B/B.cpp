/*
ARC034
2020/01/18/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  llint n;
  cin >> n;

  vector<llint> ans;
  for (llint i = n - 153; i <= n; i++) {
    llint j = i, sum = 0;
    while (0 < j) sum += j % 10, j /= 10;
    if (i + sum == n) ans.emplace_back(i);
  }
  cout << ans.size() << endl;
  for (auto &x : ans) cout << x << endl;

  return 0;
}