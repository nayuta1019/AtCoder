/*
ARC042
2019/11/28/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  for (int i = 0; i < M; i++) cin >> a[i];
  reverse(a.begin(), a.end());

  vector<int> used(N + 1, 1), ans;
  for (int i = 0; i < M; i++) {
    if (used[a[i]]) {
      used[a[i]] = 0;
      ans.push_back(a[i]);
    }
  }
  for (int i = 1; i <= N; i++) {
    if (used[i]) {
      ans.push_back(i);
    }
  }

  for (auto& x : ans) {
    cout << x << endl;
  }

  return 0;
}