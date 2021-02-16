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
      // dist[cur] += 1.0;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

int main() {
  int N;
  cin >> N;
  Graph<double> G(N);
  vector<int> x(N), y(N), t(N), r(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> t[i] >> r[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      double v = min(t[i], r[j]);
      double dist = fabs(x[i] - x[j]) * fabs(x[i] - x[j]) +
                    fabs(y[i] - y[j]) * fabs(y[i] - y[j]);
      dist = sqrt(dist);
      G[i].emplace_back(j, dist / v);
    }
  }
  auto dist = dijkstra(G, 0);
  for (auto x : dist) {
    cout << x << endl;
  }
  cout << *max_element(dist.begin(), dist.end()) << endl;
  return 0;
}