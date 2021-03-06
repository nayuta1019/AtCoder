/*
ABC161
2020/04/04/ 自力AC
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  llint n;
  cin >> n;
  queue<llint> que;
  for (llint i = 1; i < 10; i++) {
    que.push(i);
  }
  if (n < 10) {
    cout << n << endl;
    return 0;
  }

  llint cnt = 9;
  while (cnt < n) {
    llint q = que.front();
    que.pop();
    q = q * 10 + q % 10;
    if (q % 10 != 0) {
      que.push(q - 1);
      // cout << q - 1 << endl;
      cnt++;
      if (cnt == n) break;
    }
    que.push(q);
    // cout << q << endl;
    cnt++;
    if (cnt == n) break;
    if (q % 10 != 9) {
      que.push(q + 1);
      // cout << q + 1 << endl;
      cnt++;
      if (cnt == n) break;
    }
  }
  cout << que.back() << endl;

  return 0;
}