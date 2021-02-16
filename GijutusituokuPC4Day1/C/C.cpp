/*
2019/08/21/ AC
*/
#include <bits / stdc++.h>

using namespace std;

// typedef
typedef long long lint;

template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

int main() {
  lint n;
  string x;
  cin >> n >> x;

  string s = "";
  lint tmp = n;
  int res = -1;
  for (lint m = 2; m <= 10; m++) {
    s = "";
    tmp = n;
    while (tmp != 0) {
      s = toString(tmp % m) + s;
      tmp /= m;
    }
    if (s == x) res = m;
  }

  cout << res << endl;

  return 0;
}