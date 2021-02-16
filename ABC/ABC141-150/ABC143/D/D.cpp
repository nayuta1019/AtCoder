/*
ABC143
2019/10/19/ 自力AC
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

int N;

vector<tuple<int, int, int>> tp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<lint> L(N);
  rep(i, N) cin >> L[i];

  sort(L.begin(), L.end());

  lint ans = 0, b, c, tmp;
  for (int i = 0; i + 1 < N; i++) {
    for (int j = i + 1; j < N; j++) {
      b = L[i], c = L[j];
      tmp = c - b;
      auto it1 = upper_bound(all(L), tmp);
      auto it2 = lower_bound(all(L), b + c);
      auto x = it1 - L.begin();
      if (x <= j) x = j + 1;
      auto y = it2 - L.begin();
      y--;
      if (L[y] < b + c) y++;
      // cout << "x = " << x << endl;
      // cout << "y = " << y << endl;
      // cout << y - x << endl;
      if (y - x < 0) continue;

      ans += y - x;
    }
  }

  cout << ans << endl;

  return 0;
}