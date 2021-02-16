/*
ABC035
2019/10/23/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

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
vector<T> dijkstra(Graph<T> &G, int s) {
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

long long N, M;
long long T, A[101010];

int main() {
  cin >> N >> M >> T;
  for (int i = 0; i < N; i++) cin >> A[i];

  Graph<long long> G(N), rG(N);
  long long a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].emplace_back(b, c);
    rG[b].emplace_back(a, c);
  }

  auto dist = dijkstra(G, 0);
  auto rdist = dijkstra(rG, 0);

  long long t = 0, res = 0;
  for (int i = 0; i < N; i++) {
    if (dist[i] == numeric_limits<long long>::max() ||
        rdist[i] == numeric_limits<long long>::max())
      continue;
    t = dist[i] + rdist[i];
    if (T < t) continue;
    res = max(res, A[i] * (T - t));
  }

  cout << res << endl;

  return 0;
}