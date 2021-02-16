/*
2019/08/06/ 解説AC
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

int N;
vector<double> p;

double dp[3100][3100];

int main() {
  cin >> N;
  p.resize(N);
  for (int i = 0; i < N; i++) cin >> p[i];

  dp[0][0] = 1.0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
    }
  }

  double res = 0.0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      cout << dp[i][j] << "\t";
    }
    cout << endl;
  }
  for (int j = (N + 1) / 2; j <= N; j++) res += dp[N][j];
  printf("%.10f\n", res);

  return 0;
}