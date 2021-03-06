/*
ABC150
2020/01/14/ 解説AC
*/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                         \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
       << " " << __FILE__ << endl;

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

/* 最大公約数 */
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

/* 最小公倍数 */
long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  return a / g * b;  // Be careful not to overflow
}

int f(int x) {
  int res = 0;
  while (x % 2 == 0) {
    x /= 2;
    res++;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  lint n, m;
  cin >> n >> m;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 1) {
      cout << 0 << endl;
      return 0;
    }
    a[i] /= 2;
  }

  int t = f(a[0]);
  for (int i = 0; i < n; i++) {
    if (f(a[i]) != t) {
      cout << 0 << endl;
      return 0;
    }
    a[i] >>= t;
  }
  m >>= t;

  lint l = 1;
  for (int i = 0; i < n; i++) {
    l = lcm(l, a[i]);
    if (l > m) {
      cout << 0 << endl;
      return 0;
    }
  }

  m /= l;
  int ans = (m + 1) / 2;
  cout << ans << endl;

  return 0;
}