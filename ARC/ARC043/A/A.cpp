/*
ARC043
2019/11/26/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N;
double A, B;
double S[101010];

int main() {
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  double E = 0, D = 0, mn = 1e18, mx = 0;
  for (int i = 0; i < N; i++) {
    E += S[i];
    mn = min(mn, S[i]);
    mx = max(mx, S[i]);
  }
  E = E / (double)N;
  D = fabs(mx - mn);

  if (D == 0) {
    cout << -1 << endl;
    return 0;
  }

  double P = B / D;
  double Q = A - (E * P);

  printf("%.12f %.12f\n", P, Q);
  return 0;
}