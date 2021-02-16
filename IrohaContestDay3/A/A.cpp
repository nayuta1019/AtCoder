/*
2020/02/14/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

long long A, B, C, D, E, F, G, H, I, J, K, L, M, N;
long long O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main() {
  cin >> A >> B >> C >> D >> E >> F >> G >> H >> I >> J >> K >> L >> M >> N >>
      O >> P >> Q >> R >> S >> T >> U >> V >> W >> X >> Y >> Z;

  cout << A - B << endl;
  cout << C + D << endl;
  cout << max(F - E + 1, 0LL) << endl;
  cout << (G + H + I) / 3 + 1 << endl;

  if (J == 0) {
    cout << "" << endl;
  } else if (J == 8) {
    cout << "dagabaji" << endl;
  } else if (J == 7) {
    cout << "agabaji" << endl;
  } else if (J == 6) {
    cout << "aabaji" << endl;
  } else if (J == 5) {
    cout << "aaaji" << endl;
  } else if (J == 4) {
    cout << "aaai" << endl;
  } else if (J == 3) {
    cout << "aaa" << endl;
  } else if (J == 2) {
    cout << "aa" << endl;
  } else if (J == 1) {
    cout << "a" << endl;
  }

  long long cnt = 0, xx = 0;
  while (true) {
    if (xx % 59 == K && xx % 61 == L) {
      cnt++;
      if (M == cnt) {
        break;
      }
    }
    xx++;
  }

  long long yy = 0;
  if (abs(xx - 6LL) >= N) {
    yy = 6;
  } else if (abs(xx - 28LL) >= N) {
    yy = 28;
  } else if (abs(xx - 496LL) >= N) {
    yy = 496;
  } else if (abs(xx - 8128LL) >= N) {
    yy = 8128;
  } else {
    yy = 33550336;
  }
  cout << min(xx, yy) << endl;
  cout << max(xx, yy) << endl;

  cout << (O + P + Q) * (R + S + T) * (U + V + W) * (X + Y + Z) % 9973LL
       << endl;

  return 0;
}