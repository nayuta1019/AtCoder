/*
AGC020
2019/11/25/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

long long K;
long long A[101010];

int main() {
  cin >> K;
  for (int i = 0; i < K; i++) cin >> A[i];

  reverse(A, A + K);

  if (A[0] != 2) {
    cout << -1 << endl;
    return 0;
  }

  long long mx = 2, mn = 2;
  for (int i = 0; i < K; i++) {
    mx = mx - (mx % A[i]) + A[i] - 1;
    mn = A[i] * ((mn + A[i] - 1) / A[i]);
  }

  reverse(A, A + K);

  long long tmx = mx, tmn = mn;
  for (int i = 0; i < K; i++) {
    tmx = A[i] * (tmx / A[i]);
    tmn = A[i] * (tmn / A[i]);
  }

  if (tmx != 2 && tmn != 2) {
    cout << -1 << endl;
  } else {
    cout << mn << " " << mx << endl;
  }

  return 0;
}