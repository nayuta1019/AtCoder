/*
2019/12/06/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, X, Y, Z;
  cin >> N >> X >> Y >> Z;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (X <= A[i] && Y <= B[i] && Z <= A[i] + B[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}