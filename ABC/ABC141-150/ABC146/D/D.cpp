/*
ABC146
2019/11/24/ 自力AC
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

vector<vector<int>> G;
int N;
map<P, int> mp;

void dfs(int v, int pv, int pc) {
  int color = 0;
  for (auto nv : G[v]) {
    if (pv == nv) continue;
    color++;
    if (pc == color) color++;
    mp[P(v, nv)] = color;
    mp[P(nv, v)] = color;
    dfs(nv, v, color);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  G.assign(N, vector<int>());
  int a, b;
  vector<P> ab;
  rep(i, N - 1) {
    cin >> a >> b;
    a--, b--;
    ab.emplace_back(a, b);
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  dfs(0, -1, -1);

  int k = 0;
  vector<int> ans;
  for (int i = 0; i < N - 1; i++) {
    ans.emplace_back(mp[ab[i]]);
    k = max(k, ans.back());
  }

  cout << k << endl;
  for (auto x : ans) {
    cout << x << endl;
  }

  return 0;
}