/*
ABC144
2019/10/27/ 自力AC
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

lint N;

/* nの約数を列挙 */
vector<long long> divisors(long long n) {
  vector<long long> res;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (n / i == i) continue;  // 上の行で追加済み。
    res.push_back(n / i);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  vector<lint> tmp = divisors(N);
  sort(all(tmp));
  lint ans = 1e18;
  for (int i = 0; i < (int)tmp.size() / 2 + 1; i++) {
    lint x = tmp[i];
    lint y = N / x;
    ans = min(ans, (x - 1) + (y - 1));
  }

  cout << ans << endl;

  return 0;
}