/**
ABC126
2019/05/27/ 解説AC
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

int N;
Graph G;

vector<int> res;

void dfs(int v, int p, int c) {
  res[v] = c;
  for (auto e : G[v]) {
    if (e.first == p) continue;
    if (e.second & 1)
      dfs(e.first, v, 1 - c);
    else
      dfs(e.first, v, c);
  }
}

int main() {
  cin >> N;
  G.assign(N, vector<Edge>());
  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back(Edge(v, w));
    G[v].push_back(Edge(u, w));
  }
  res.assign(N, 0);
  dfs(0, -1, 1);
  for (auto v : res) cout << v << endl;

  return 0;
}
