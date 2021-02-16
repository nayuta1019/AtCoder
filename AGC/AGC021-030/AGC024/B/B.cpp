/*
AGC024
2019/10/14/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int P[201010], dp[201010];

int rec(int n) {
  if (dp[n] != 0) return dp[n];
  if (n == 0) return 1;
  if (P[n - 1] < P[n])
    return dp[n] = rec(n - 1) + 1;
  else
    return dp[n] = 1;
}

int main() {
  cin >> N;
  int x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    P[x - 1] = i;
  }
  for (int i = 0; i < N; i++) {
    cout << P[i] << " ";
  }
  cout << endl;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, rec(i));
  }
  cout << N - ans << endl;

  return 0;
}