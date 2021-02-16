/*
ABC132
2019/06/29/ 自力AC
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

long long modpow(long long a, int p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    int halfP = p / 2;
    long long half = modpow(a, halfP);
    return half * half % MOD;
  } else {
    return a * modpow(a, p - 1) % MOD;
  }
}
long long calcComb(int a, int b) {
  if (b > a - b) return calcComb(a, a - b);

  long long ansMul = 1;
  long long ansDiv = 1;
  for (int i = 0; i < b; i++) {
    ansMul *= (a - i);
    ansDiv *= (i + 1);
    ansMul %= MOD;
    ansDiv %= MOD;
  }
  // ansDivの逆元
  long long ans = ansMul * modpow(ansDiv, MOD - 2) % MOD;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  lint n, k;
  cin >> n >> k;

  lint sum = 0;
  FOR(i, 1, k + 1) {
    lint ans = 0;
    lint p = n - k + 1;
    lint q = i;

    ans = calcComb(p, q) % MOD;
    ans = (ans * calcComb(k - 1, i - 1)) % MOD;

    if (i - 1 > n - k) ans = 0;

    cout << ans << endl;
  }
  return 0;
}