/*
ABC142
2019/09/28/ 自力AC
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

vector<lint> divisors(lint n) {
  vector<lint> res;
  for (lint i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (n / i == i) continue;  // 上の行で追加済み。
    res.push_back(n / i);
  }
  return res;
}

// 最大公約数
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool is_prime(lint n) {
  for (lint i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  lint A, B;
  cin >> A >> B;

  vector<lint> A_div, B_div, AB_div;
  A_div = divisors(A);
  B_div = divisors(B);
  sort(all(A_div));
  sort(all(B_div));
  lint a = 0, b = 0;
  while (a < A_div.size() && b < B_div.size()) {
    if (A_div[a] == B_div[b]) {
      AB_div.push_back(A_div[a]);
      a++;
      b++;
    } else {
      if (A_div[a] < B_div[b]) {
        a++;
      } else {
        b++;
      }
    }
  }

  lint res = 0;
  rep(i, (int)AB_div.size()) {
    if (is_prime(AB_div[i])) res++;
  }

  cout << res << endl;

  return 0;
}