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
int n, m;
int verused[100005];
Graph edgeused;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  G.assign(n, vector<int>());
  edgeused.assign(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
    edgeused[a].push_back(1);
    edgeused[b].push_back(1);
    verused[a]++;
    verused[b]++;
  }
  vector<P> ans;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int ver = que.front();
    que.pop();
    if (verused[ver] == 0) continue;
    int len = verused[ver] - verused[ver] % 2;
    for (int i = 0; i < len; i++) {
      // edgeを使っていたらcontinue;
      if (edgeused[ver][i] == 0) continue;
      que.push(G[ver][i]);
      verused[ver]--;
      ans.push_back(P(ver, G[ver][i]));
      // edgeを使ったことにする
      edgeused[ver][i]--;
    }
  }
  rep(i, n) {
    if (verused[i] != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (auto x : ans) {
    cout << x.first + 1 << " " << x.second + 1 << endl;
  }

  return 0;
}