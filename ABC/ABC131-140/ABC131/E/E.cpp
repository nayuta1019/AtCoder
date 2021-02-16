/*
ABC131
2019/10/15/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> ans;

int main() {
  cin >> N >> K;

  int cnt = (N - 1) * (N - 2) / 2;

  if (cnt < K) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 2; i <= N; i++) {
    ans.push_back({1, i});
  }

  int c = cnt - K;
  for (int i = 2; i < N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (c <= 0) continue;
      ans.push_back({i, j});
      c--;
    }
  }

  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}