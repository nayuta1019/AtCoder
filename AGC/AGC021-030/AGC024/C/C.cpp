/*
AGC024
2019/09/25/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int N;
lint A[201010];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  lint res = 0;
  if (A[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < N - 1; i++) {
    if (A[i] + 1 < A[i + 1]) {
      res = -1;
      break;
    }

    if (A[i] + 1 == A[i + 1]) {
      res++;
    } else {
      res += A[i + 1];
    }
  }

  cout << res << endl;

  return 0;
}