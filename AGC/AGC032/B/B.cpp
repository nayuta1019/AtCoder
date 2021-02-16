/*
AGC032
2019/12/20/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> ans;
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (N % 2) {
        if (i + j == N) continue;
        ans.emplace_back(i, j);
      } else {
        if (i + j == N + 1) continue;
        ans.emplace_back(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}