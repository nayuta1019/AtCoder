/*
2019/12/01/ 自力AC
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

set<string> st;
// i -> N の間にxがあるか
int ok[30303][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string s;
  cin >> N >> s;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      ok[i][j] = -1;
    }
  }
  for (int i = N - 1; 0 <= i; i--) {
    int num = s[i] - '0';
    for (int j = 0; j < 10; j++) {
      ok[i][j] = ok[i + 1][j];
    }
    ok[i][num] = i;
  }

  for (int i = 0; i + 2 < N; i++) {
    for (int j = 0; j < 10; j++) {
      if (ok[i + 1][j] == -1) continue;

      for (int k = 0; k < 10; k++) {
        int id = ok[i + 1][j];
        if (ok[id + 1][k] == -1) continue;
        string c = "";
        c += s[i];
        c += to_string(j);
        c += to_string(k);
        // cout << c << endl;
        st.insert(c);
      }
    }
  }

  cout << st.size() << endl;

  return 0;
}