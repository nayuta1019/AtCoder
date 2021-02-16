/**
ABC128
2019/05/27/ 解説AC
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

int N, K;
vector<lint> V;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;
  V.resize(N);
  for (int i = 0; i < N; i++) cin >> V[i];

  lint res = 0;
  for (int p = 0; p <= min(K, N); p++) {
    for (int q = 0; p + q <= min(K, N); q++) {
      vector<lint> v;
      lint cur = 0;
      //左から取る
      for (int i = 0; i < p; i++) {
        v.push_back(V[i]), cur += V[i];
      }
      //右から取る
      for (int i = 0; i < q; i++) {
        v.push_back(V[N - 1 - i]), cur += V[N - 1 - i];
      }

      sort(all(v));

      //捨てる分
      for (int i = 0; i < min(K - p - q, (int)v.size()); i++) {
        if (v[i] < 0) cur -= v[i];
      }
      chmax(res, cur);
    }
  }

  cout << res << endl;

  return 0;
}