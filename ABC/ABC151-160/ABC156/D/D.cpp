/*
ABC156
2020/02/22/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long llint;
typedef unsigned long long ull;
typedef complex<long double> Complex;
typedef pair<int, int> P;
typedef tuple<int, int, int> TP;
typedef vector<int> vec;
typedef vector<vec> mat;

// constant
const long long MOD = (long long)1e9 + 7;
const int INF = (int)1e9;
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

/* べき乗(mのn乗)を計算する関数. O(logn) */
template <typename T>
T modpow(T m, T n, const T& p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}
/* フェルマーの小定理を使って二項係数を計算. O(r) */
template <typename T>
T binomial(T n, T r, const T& p) {
  if (r > n - r) return binomial(n, n - r, p);
  T ansMul = 1;
  T ansDiv = 1;
  for (T i = 0; i < r; i++) {
    ansMul *= (n - i);
    ansDiv *= (i + 1);
    ansMul %= p;
    ansDiv %= p;
  }
  // ansDivの逆元
  T ans = (ansMul * modpow(ansDiv, p - 2, p)) % p;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  llint n, a, b;
  cin >> n >> a >> b;

  llint tot = modpow(2LL, n, MOD) - 1;
  if (tot < 0) tot += MOD;
  tot -= binomial(n, a, MOD);
  if (tot < 0) tot += MOD;
  tot -= binomial(n, b, MOD);
  if (tot < 0) tot += MOD;
  cout << tot << endl;
  return 0;
}