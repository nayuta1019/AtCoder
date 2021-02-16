/*
ABC003
2019/07/09/ 解説AC
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

lint cmb[1010][1010];

void calc_cmb() {
  rep(i, 1000) {
    cmb[i][0] = cmb[i][i] = 1;
    FOR(j, 1, i) cmb[i][j] = (cmb[i - 1][j - 1] + cmb[i - 1][j]) % MOD;
  }
}

long long ncr(long long a, long long b) { return cmb[a][b]; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  lint r, c, x, y, d, l;
  cin >> r >> c >> x >> y >> d >> l;
  calc_cmb();

  lint ans = 0;
  for (int bit = 0; bit < (1 << 4); bit++) {
    int xx = x, yy = y;
    if ((1 & (bit >> 0)) == 1) xx--;
    if ((1 & (bit >> 1)) == 1) yy--;
    if ((1 & (bit >> 2)) == 1) xx--;
    if ((1 & (bit >> 3)) == 1) yy--;

    if (xx <= 0 || yy <= 0) continue;
    if (xx * yy - d < 0) continue;
    int tmp = ncr(xx * yy, d) * ncr(xx * yy - d, l) % MOD;

    if (__builtin_popcount(bit) % 2) {
      ans = (ans - tmp + MOD) % MOD;
    } else {
      ans = (ans + tmp) % MOD;
    }
  }

  cout << ans * (r - x + 1) % MOD * (c - y + 1) % MOD << endl;

  return 0;
}