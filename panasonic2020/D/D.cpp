/*
2020/03/14/ 自力AC
*/
#include <bits / stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long llint;
typedef unsigned long long ull;
typedef complex<long double> Complex;
typedef pair<int, int> P;
typedef tuple<int, int, int> TP;
typedef vector<int> vec;
typedef vector<vec> mat;

// constant
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double pi = 3.14159265358979323846;

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

set<string> ans;
int n;
int rec(string s, int c) {
  if (s.size() == n) {
    ans.insert(s);
    return 0;
  }

  for (int i = 0; i <= c + 1; i++) {
    char d = (char)('a' + i);
    s += d;
    int nc = max(c, i);
    rec(s, nc);
    s.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  string s = "";
  s += 'a';
  rec(s, 0);
  for (auto& v : ans) {
    cout << v << endl;
  }

  return 0;
}