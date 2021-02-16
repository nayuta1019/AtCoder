/*
2019/10/10/ 自力AC
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

  vector<int> negative, positive;
  int a;
  rep(i, N) {
    cin >> a;
    if (a < 0)
      negative.push_back(a);
    else
      positive.push_back(a);
  }

  int x, y;
  vector<P> p;
  if (negative.empty()) {  // all positive
    sort(all(positive));
    y = positive.back();
    positive.pop_back();
    reverse(all(positive));
    x = positive.back();
    positive.pop_back();
    p.push_back(P(x, y));
    if (x - y < 0) {
      negative.push_back(x - y);

    } else {
      positive.push_back(x - y);
      if (1 < positive.size()) {
        sort(all(positive));
        x = positive.back();
        positive.pop_back();
        reverse(all(positive));
        y = positive.back();
        positive.pop_back();

        if (positive.empty()) {
          positive.push_back(x - y);
          p.push_back(P(x, y));
        } else {
          negative.push_back(y - x);
          p.push_back(P(y, x));
        }
      }
    }

  } else if (positive.empty()) {  // all negative
    sort(all(negative));
    x = negative.back();
    negative.pop_back();
    reverse(all(negative));
    y = negative.back();
    negative.pop_back();
    positive.push_back(x - y);
    p.push_back(P(x, y));
  }

  while (!negative.empty()) {
    x = positive.back();
    y = negative.back();
    positive.pop_back();
    negative.pop_back();

    if (positive.size() <= negative.size()) {
      positive.push_back(x - y);
      p.push_back(P(x, y));
    } else {
      negative.push_back(y - x);
      p.push_back(P(y, x));
    }
  }

  cout << positive[0] << endl;
  for (auto x : p) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}