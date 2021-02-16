/*
ABC134
2019/07/20/ 未完成
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

int n, cnt;
int ans[200005], a[200005];
bool flag;

int dfs(int p, int v) {
  int x = 0;
  if (p * (v + 1) <= n) {
    v++;
    x += dfs(p, v);
    v--;
  } else {
    if (a[p * v] % 2 == 1) {
      if (ans[p * v] != -1) {
        if (ans[p * v] != 1) flag = false;
      }
      ans[p * v] = 1;
      cnt++;
      return 1;
    } else {
      if (ans[p * v] != -1) {
        if (ans[p * v] != 0) flag = false;
      }
      return 0;
    }
  }

  if (x % 2 == 1) {
    if (a[p * v] == 0) {
      x++;
      if (ans[p * v] != -1) {
        if (ans[p * v] != 1) flag = false;
      }
      ans[p * v] = 1;  //ボールを入れる
      cnt++;
    }
  } else {
    if (a[p * v] == 1) {
      x++;
      if (ans[p * v] != -1) {
        if (ans[p * v] != 1) flag = false;
      }
      ans[p * v] = 1;
      cnt++;
    }
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  rep(i, n) cin >> a[i + 1];

  rep(i, n + 1) ans[i] = -1;
  flag = true;
  cnt = 0;

  int sum = 0;
  for (int i = 2; i <= n; i++) {
    if (ans[i] == -1) {
      sum += dfs(i, 1);
    }
    if (!flag) break;
  }

  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  if (a[1] % 2 == 1) {
    if (sum % 2 == 0) {
      ans[1] = 1;
      cnt++;
    }
  } else {
    if (sum % 2 == 1) {
      ans[1] = 1;
      cnt++;
    }
  }
  /*
    FOR(i, 1, n + 1) { cout << ans[i] << " "; }
    cout << endl;
  */
  if (cnt == 0) {
    cout << 0 << endl;
  } else {
    cout << cnt << endl;
    FOR(i, 1, n + 1) {
      if (ans[i] != -1) {
        cnt--;
        cout << i << (cnt != 0 ? " " : "");
      }
    }
    cout << endl;
  }

  return 0;
}