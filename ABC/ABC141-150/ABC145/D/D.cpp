/*
ABC145
2019/11/16/ 自力AC
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
const long long MOD = (long long)1e9 + 7;
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

lint x, y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> x >> y;
  if (x * 2 == y || y * 2 == x) {
    cout << 1 << endl;
    return 0;
  }

  lint tx = x, ty = y, a = 0, b = 0;
  while (tx != 0 || ty != 0) {
    if (tx == 2 * ty) {
      tx -= 2;
      ty -= 1;
      b++;
    } else if (2 * tx == ty) {
      tx -= 1;
      ty -= 2;
      a++;
    } else if (1 <= tx && 2 <= ty) {
      tx -= 1;
      ty -= 2;
      a++;
    } else if (2 <= tx && 1 <= ty) {
      tx -= 2;
      ty -= 1;
      b++;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }

  lint n = a + b + 1;
  lint k = min(a, b) + 1;
  cout << binomial(n - 1, k - 1, MOD) % MOD << endl;

  return 0;
}