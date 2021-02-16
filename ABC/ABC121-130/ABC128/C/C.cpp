/**
ABC128
2019/05/26/ 自力AC
**/
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

  int N, M;
  cin >> N >> M;

  vector<int> p(M);
  vector<vector<int>> s(M, vector<int>());

  rep(i, M) {
    int k;
    cin >> k;

    rep(j, k) {
      int x;
      cin >> x;
      x--;
      s[i].push_back(x);
    }
  }

  rep(i, M) { cin >> p[i]; }

  int ans = 0;
  int tmp[10] = {0};  //電球
  for (int bit = 0; bit < 1 << N; bit++) {
    rep(i, 10) tmp[i] = 0;
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) {
        for (int j = 0; j < M; j++) {
          for (int k = 0; k < s[j].size(); k++) {
            if (s[j][k] == i) tmp[j]++;
          }
        }
      }
    }
    bool flag = true;
    rep(i, M) {
      if (tmp[i] % 2 != p[i]) flag = false;
    }
    if (flag) ans++;
  }

  cout << ans << endl;

  return 0;
}