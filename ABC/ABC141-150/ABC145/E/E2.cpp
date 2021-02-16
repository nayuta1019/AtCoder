/*
ABC145
2020/01/27/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int dp[3030];

int main() {
  int n, t, a, b;
  cin >> n >> t;
  vector<P> ab;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ab.emplace_back(a, b);
  }
  sort(ab.begin(), ab.end());

  for (int i = 0; i < n; i++) {
    for (int j = t - 1; 0 <= j; j--) {
      dp[min(t, j + ab[i].first)] =
          max(dp[min(t, j + ab[i].first)], dp[j] + ab[i].second);
    }
  }

  cout << dp[t] << endl;

  return 0;
}