/*
ABC129
2019/07/29/ 自力AC
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

int h, w;
char s[2222][2222];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w;
  FOR(y, 1, h + 1) FOR(x, 1, w + 1) cin >> s[y][x];

  vector<vector<int>> v1(h + 2, vector<int>(w + 2, 0)),
      v2(h + 2, vector<int>(w + 2, 0));

  FOR(y, 1, h + 1) {
    FOR(x, 1, w + 1) {
      if (s[y][x] == '#') continue;
      v1[y][x] = v1[y][x - 1] + 1;
      v2[y][x] = v2[y - 1][x] + 1;
    }
  }

  for (int y = h; 0 <= y; y--) {
    for (int x = w; 0 <= x; x--) {
      if (s[y][x] == '#') continue;
      v1[y][x] = max(v1[y][x + 1], v1[y][x]);
      v2[y][x] = max(v2[y + 1][x], v2[y][x]);
    }
  }

  int ans = 0;
  FOR(y, 1, h + 1) {
    FOR(x, 1, w + 1) {
      if (s[y][x] == '#') continue;
      ans = max(ans, v1[y][x] + v2[y][x] - 1);
    }
  }

  cout << ans << endl;

  return 0;
}