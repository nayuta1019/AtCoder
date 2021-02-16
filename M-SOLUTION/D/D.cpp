/**
M-SOLUTION
2019/06/01/ 自力AC
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

using Graph = vector<vector<int>>;
Graph G;
int n;
vector<P> vp;

void dfs(int v, int p, int rank) {
  vp.push_back(make_pair(rank, v));
  for (auto nv : G[v]) {
    if (nv == p) continue;
    dfs(nv, v, rank + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  G.assign(n, vector<int>());
  int a, b;
  rep(i, n - 1) {
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  sort(c.rbegin(), c.rend());

  dfs(0, -1, 0);

  sort(all(vp));
  vector<int> res(n);
  int cnt = 0;
  lint sum = 0;
  for (auto v : vp) {
    res[v.second] = c[cnt];
    cnt++;
  }
  FOR(i, 1, n) sum += c[i];
  cout << sum << endl;
  rep(i, n) { cout << res[i] << (i == n - 1 ? "" : " "); }
  cout << endl;

  return 0;
}