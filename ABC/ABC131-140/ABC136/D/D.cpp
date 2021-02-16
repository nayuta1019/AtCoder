/*
ABC136
2019/08/04/ 自力AC
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  vector<lint> ans(s.size() + 1, 0);
  lint r = 0, l = 0;
  rep(i, (int)s.size() - 1) {
    if (s[i] == 'R') r++;
    if (s[i] == 'R' && s[i + 1] == 'L') {
      ans[i] += (r + 1) / 2;
      ans[i + 1] += r / 2;
      r = 0;
    }
  }

  for (int i = (int)s.size() - 1; 0 < i; i--) {
    if (s[i] == 'L') l++;
    if (s[i] == 'L' && s[i - 1] == 'R') {
      ans[i] += (l + 1) / 2;
      ans[i - 1] += l / 2;
      l = 0;
    }
  }

  for (int i = 0; i < s.size(); i++) {
    cout << ans[i] << (i != (int)s.size() - 1 ? " " : "");
  }
  cout << "\n";

  return 0;
}