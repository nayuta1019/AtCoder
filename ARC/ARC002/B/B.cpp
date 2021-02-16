/*
ARC002
2019/11/17/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}

string s;
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool uruu(int y) {
  if (y % 4 == 0) {
    if (y % 100 == 0) {
      if (y % 400 == 0)
        return true;
      else
        return false;
    } else
      return true;
  } else
    return false;
}

int main() {
  cin >> s;
  int y = toInt(s.substr(0, 4));
  int m = toInt(s.substr(5, 2));
  int d = toInt(s.substr(8, 2));

  if (uruu(y)) a[2] = 29;
  bool f = true;
  for (int j = m; j < 13; j++) {
    for (int k = 1; k < a[j] + 1; k++) {
      if (f) k = d, f = false;
      if (y % (j * k) == 0) {
        cout << y << "/";
        cout << setfill('0') << right << setw(2) << j << "/";
        cout << setfill('0') << right << setw(2) << k << endl;
        return 0;
      }
    }
  }
  cout << y + 1 << "/";
  cout << setfill('0') << right << setw(2) << 1 << "/";
  cout << setfill('0') << right << setw(2) << 1 << endl;

  return 0;
}