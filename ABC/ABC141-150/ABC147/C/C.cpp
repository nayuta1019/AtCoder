/*
ABC147
2019/12/11/ 自力AC
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

  int N;
  cin >> N;
  vector<vector<P>> xy(N, vector<P>());
  rep(i, N) {
    int A;
    cin >> A;
    rep(j, A) {
      int x, y;
      cin >> x >> y;
      x--;
      xy[i].emplace_back(x, y);
    }
  }

  int ans = 0;
  rep(bit, 1 << N) {
    vector<int> id(N, 0);
    rep(k, N) {
      if (bit >> k & 1) {
        id[k] = 1;
      }
    }

    bool ok = true;
    rep(i, N) {
      if (id[i] == 0) continue;
      for (auto v : xy[i]) {
        if (id[v.first] == 0 && v.second == 1) ok = false;
        if (id[v.first] == 1 && v.second == 0) ok = false;
      }
    }
    int cnt = 0;
    if (ok) {
      rep(i, N) {
        if (id[i]) cnt++;
      }
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;

  return 0;
}