/*
ABC152
2020/01/20/ 解説AC
*/
#include <bits/stdc++.h>

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
const int INF = (int)1e18;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double pi = 3.14159265358979323846;

// conversion
inline llint toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  llint ret = v;
  return ret;
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

P conv(llint x) {
  llint f = 0, b;
  b = x % 10;
  while (x) f = x, x /= 10;
  return P(f, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  llint n;
  cin >> n;

  map<P, int> freq;
  for (llint i = 1; i <= n; i++) {
    P p = conv(i);
    freq[p]++;
  }
  llint ans = 0;
  for (llint i = 1; i <= n; i++) {
    P p = conv(i);
    P q(p.second, p.first);
    ans += freq[q];
  }
  cout << ans << endl;

  return 0;
}