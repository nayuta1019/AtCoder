/*
ABC145
2019/11/16/ 自力AC
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
int x[1010], y[1010], id[1010];

int main() {
  cin >> N;
  rep(i, N) {
    cin >> x[i] >> y[i];
    id[i] = i;
  }

  double ans = 0;
  int cnt = 0;
  do {
    cnt++;

    for (int i = 0; i < N - 1; i++) {
      double tmp =
          (double)(x[id[i]] - x[id[i + 1]]) * (x[id[i]] - x[id[i + 1]]);
      tmp += (double)(y[id[i]] - y[id[i + 1]]) * (y[id[i]] - y[id[i + 1]]);

      ans += sqrt(tmp);
    }

  } while (next_permutation(id, id + N));

  printf("%.12f\n", (double)ans / (double)cnt);
  return 0;
}