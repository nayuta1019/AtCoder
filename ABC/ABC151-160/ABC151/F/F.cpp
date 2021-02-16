#include <bits/stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long lint;
typedef unsigned long long ull;
typedef complex<long double> Complex;
typedef pair<int, int> P;
typedef tuple<int, int, int> TP;
typedef vector<int> vec;
typedef vector<vec> mat;

// constant
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double pi = 3.14159265358979323846;

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

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

int n;
int x[1010], y[1010];
int xl = 1010, xr, yl = 1010, yr;

int ok(long double m) {
  bool xok = false, yok = false;
  long double l = 0, r = 1e20;
  rep(i, 100) {
    long double = xm = (l + r) / 2;
    if (xm - m <= xl && xr <= xm + m) {
      xok = true;
    }
  }

}

int main() {
  cin >> n;
  rep(i, n) {
    cin >> x[i] >> y[i];
    xl = min(xl, x[i]);
    xr = max(xr, x[i]);
    yl = min(yl, y[i]);
    yr = max(yr, y[i]);
  }

  long double l = 0, r = 1e20;
  rep(i, 100) {
    long double = m = (l + r) / 2;
    if (ok(m))
      r = m;
    else
      l = m;
  }

  printf("%.12f\n", l / 2);

  return 0;
}