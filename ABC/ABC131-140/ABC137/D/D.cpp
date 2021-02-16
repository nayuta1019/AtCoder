/*
ABC137
2019/08/12/ 解説AC
*/
#define _USE_MATH_DEFINE
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  lint n, m;
  cin >> n >> m;

  priority_queue<P, vector<P>, greater<P>> ab;
  priority_queue<P> que;
  rep(i, n) {
    lint a, b;
    cin >> a >> b;
    ab.push(P(a, b));
  }

  lint ans = 0;
  int d = 1;
  ab.push(P(INF, INF));
  while (d <= m) {
    P p = ab.top();

    // cout << d << " " << p.first << " " << p.second << endl;

    if (p.first <= d) {
      que.push(P(p.second, p.first));
      ab.pop();
    } else {
      if (que.empty()) {
        d++;
        continue;
      }
      P pp = que.top();
      que.pop();
      ans += pp.first;
      d++;
    }
  }

  cout << ans << endl;

  return 0;
}