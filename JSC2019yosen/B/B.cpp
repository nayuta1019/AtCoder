/*
2019/08/24/ 自力AC
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
const lint MOD = (lint)1e9 + 7;
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

  lint N, K;
  cin >> N >> K;
  vector<lint> A(N);
  rep(i, N) cin >> A[i];

  vector<pair<lint, lint>> B(N);
  lint res = 0;
  rep(i, N) {
    for (int r = i + 1; r < N; r++) {
      if (A[r] < A[i]) B[i].second += 1;
    }
    for (int l = 0; l < i; l++) {
      if (A[l] < A[i]) B[i].first += 1;
    }
  }

  lint r = K * (1 + K) / 2LL;
  lint l = (K - 1) * K / 2LL;
  r %= MOD;
  l %= MOD;

  rep(i, N) {
    res += B[i].second * r % MOD;
    res %= MOD;
    res += B[i].first * l % MOD;
    res %= MOD;
  }

  cout << res << endl;

  return 0;
}