/*
2019/12/15/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  string in, sl, sr;
  cout << 0 << endl << flush;
  cin >> in;
  if (in == "Vacant") return 0;
  sl = in;
  cout << N - 1 << endl << flush;
  cin >> in;
  if (in == "Vacant") return 0;
  sr = in;

  int left = 0, right = N - 1, mid;
  while (1) {
    mid = (left + right) / 2;
    cout << mid << endl << flush;

    cin >> in;
    if (in == "Vacant") break;
    {  // [left, mid]
      if ((mid - left) % 2) {
        if (sl == in) {
          sr = in;
          right = mid;
        }
      } else {
        if (sl != in) {
          sr = in;
          right = mid;
        }
      }
    }

    {  // [mid, r]
      if ((right - mid) % 2) {
        if (sr == in) {
          sl = in;
          left = mid;
        }
      } else {
        if (sr != in) {
          sl = in;
          left = mid;
        }
      }
    }
  }

  return 0;
}