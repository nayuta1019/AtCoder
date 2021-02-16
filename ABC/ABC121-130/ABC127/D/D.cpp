/**
ABC127
2019/05/25/ 自力AC
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
typedef long long ll;
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
  vector<ll> A(N);
  vector<pair<ll, ll>> BC;
  rep(i, N) cin >> A[i];

  rep(i, M) {
    ll b, c;
    cin >> b >> c;
    BC.push_back(make_pair(c, b));
  }
  sort(A.begin(), A.end());
  sort(BC.begin(), BC.end());
  reverse(all(A));
  reverse(all(BC));

  int i = 0, j = 0;
  ll ans = 0;
  for (int p = 0; p < N; p++) {
    if (A[j] < BC[i].first && i < M) {
      ans += BC[i].first;
      if (1 < BC[i].second)
        BC[i].second--;
      else
        i++;
    } else {
      ans += A[j];
      j++;
    }
  }

  cout << ans << endl;

  return 0;
}