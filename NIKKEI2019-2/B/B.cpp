/*
2019/11/11/ 解説AC
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
const long long MOD = 998244353;
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

template <typename T>
T modpow(T m, T n, const T& p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}

lint cnt[101010];
lint maxd = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  lint d;
  rep(i, N) {
    cin >> d;
    if (i == 0 && d != 0) {
      cout << 0 << endl;
      return 0;
    }
    if (i != 0 && d == 0) {
      cout << 0 << endl;
      return 0;
    }
    cnt[d]++;
    maxd = max(maxd, d);
  }

  lint ans = 1;
  for (int i = 1; i <= maxd; i++) {
    ans *= modpow(cnt[i - 1], cnt[i], MOD);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}