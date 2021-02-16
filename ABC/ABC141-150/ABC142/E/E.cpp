/*
ABC142
2019/09/29/ 解説AC
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

int N, M;
lint a[1010], b[1010], c[1010][20];
lint dp[1 << 12];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  rep(i, M) {
    cin >> a[i] >> b[i];
    rep(j, b[i]) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }

  for (int i = 0; i < 1 << N; i++) dp[i] = INF;
  dp[0] = 0;

  for (int i = 0; i < M; i++) {
    int now = 0;
    for (int j = 0; j < b[i]; j++) {
      now |= (1 << (c[i][j]));
    }

    for (int bit = 0; bit < 1 << N; bit++) {
      chmin(dp[bit | now], dp[bit] + a[i]);
    }
  }

  if (dp[(1 << N) - 1] == INF) dp[(1 << N) - 1] = -1;
  cout << dp[(1 << N) - 1] << endl;

  return 0;
}