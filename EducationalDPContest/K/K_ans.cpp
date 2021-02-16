/*
2019/08/07/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

//
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
//

int N, K, A[101];

int dp[101010];  // dp[k] := k個の石からなる山で先手が勝ち状態か(=1なら勝ち状態)

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];

  for (int k = 0; k < K + 1; k++) {
    int lose = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
      if (0 <= k - A[i]) {
        cnt++;
        if (!dp[k - A[i]]) lose++;
      }
    }

    //遷移先が無ければ負け
    if (cnt == 0)
      dp[k] = 0;
    else if (0 < lose)
      dp[k] = 1;
    else
      dp[k] = 0;
  }

  if (dp[K])
    cout << "First\n";
  else
    cout << "Second\n";

  return 0;
}