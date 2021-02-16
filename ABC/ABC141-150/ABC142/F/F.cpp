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
int N, M;
int A[1010], B[1010];
bool visited[1010];
vector<int> visit, trace, ans;

void check(int v, int e) {
  vector<int> ver;
  int j = (int)trace.size() - 1;
  // while (trace[j] != e) j--;
  while (0 < j && trace[j] != v) {
    ver.push_back(trace[j]);
    j--;
  }
  ver.push_back(v);
  reverse(all(ver));

  if (ver.size() == 2) {
    ans = ver;
    return;
  }

  ver.push_back(v);
  // for (auto x : ver) cout << x << " ";
  // cout << endl;

  bool used[1010] = {false};
  for (int i = 0; i < ver.size(); i++) used[ver[i]] = true;
  vector<int> tmp;
  for (int i = 0; i < (int)ver.size() - 1; i++) {
    int k = ver[i];
    tmp.push_back(k);
    for (auto nv : G[k]) {
      if (nv == ver[i + 1]) continue;

      if (used[nv]) {
        // cout << "nv : k = " << nv << " " << k << endl;
        // tmp.push_back(nv);

        trace = tmp;
        check(nv, k);
        return;
      }
    }
  }
  ver.pop_back();
  ans = ver;
  return;
}

void dfs(int v, int p) {
  if (visited[v]) {
    trace = visit;
    check(v, p);
    return;
  }
  for (auto nv : G[v]) {
    // if (nv == p) continue;
    visit.push_back(v);
    visited[v] = true;
    dfs(nv, v);
    visited[v] = false;
    visit.pop_back();
  }
  if (ans.size() != 0) return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  G.assign(N, vector<int>());
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    G[A[i]].push_back(B[i]);
  }

  rep(i, N) {
    dfs(i, -1);
    if (ans.size() != 0) break;
  }

  if (ans.size() == 0) {
    cout << -1 << endl;
  } else {
    cout << ans.size() << endl;
    for (auto v : ans) {
      cout << v + 1 << endl;
    }
  }

  return 0;
}
