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
typedef pair<lint, lint> P;
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

long long modpow(long long m, int n) {
  if (n == 0) return 1;
  long long ret = modpow(m * m % MOD, n / 2);
  if (n % 2) ret *= m;
  return ret % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  lint n, m, k;
  cin >> n >> m >> k;
  lint C = 1;
  for (int i = 0; i < k - 2; i++) {
    C *= (n * m - 2 - i), C %= MOD;
    C *= modpow(i + 1, MOD - 2), C %= MOD;
  }

  lint ansx = 0;
  for (lint i = 1; i <= m; i++) {
    ansx += (m - i) * i % MOD, ansx %= MOD;
  }
  ansx *= n * n % MOD, ansx %= MOD;
  ansx *= C, ansx %= MOD;

  lint ansy = 0;
  for (lint i = 1; i <= n; i++) {
    ansy += (n - i) * i % MOD, ansy %= MOD;
  }
  ansy *= m * m % MOD, ansy %= MOD;
  ansy *= C, ansy %= MOD;

  cout << (ansx + ansy) % MOD << endl;

  return 0;
}