/*
2019/11/10/ 解説AC
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

template <typename T>
struct edge {
  int from, to;
  T cost;
  edge(int t, T c) { to = t, cost = c; }
  edge(int f, int t, T c) { from = f, to = t, cost = c; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using Graph = vector<Edges<T>>;

template <typename T>
vector<T> dijkstra(Graph<T>& G, int s) {
  const auto INF = numeric_limits<T>::max();  // Be careful not to overflow
  vector<T> dist(G.size(), INF);
  using Pli = pair<T, int>;
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  dist[s] = 0;
  que.emplace(dist[s], s);  // cost, from
  while (!que.empty()) {
    Pli p = que.top();
    que.pop();
    T cost = p.first;
    int cur = p.second;
    if (dist[cur] < cost) continue;
    for (auto e : G[cur]) {
      auto next_cost = dist[cur] + e.cost;
      if (dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  Graph<lint> G(n);
  int l, r;
  lint c;
  FOR(i, 1, n) G[i].emplace_back(i - 1, 0);
  rep(i, m) {
    cin >> l >> r >> c;
    l--, r--;
    G[l].emplace_back(r, c);
  }
  auto dist = dijkstra(G, 0);

  if (dist[n - 1] == numeric_limits<lint>::max()) {
    cout << -1 << endl;
  } else {
    cout << dist[n - 1] << endl;
  }

  return 0;
}