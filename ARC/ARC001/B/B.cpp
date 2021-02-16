/*
ARC001
2019/11/14/ 自力AC
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

int A, B;
const int N = 60;
int main() {
  cin >> A >> B;
  A += 10, B += 10;
  Graph<int> G(70);
  for (int i = 0; i + 1 <= N; i++) {
    G[i].emplace_back(i + 1, 1);
  }
  for (int i = N; 0 <= i - 1; i--) {
    G[i].emplace_back(i - 1, 1);
  }
  for (int i = A; i + 5 <= N; i += 5) {
    G[i].emplace_back(i + 5, 1);
  }
  for (int i = A; 0 <= i - 5; i -= 5) {
    G[i].emplace_back(i - 5, 1);
  }
  for (int i = A; i + 10 <= N; i += 10) {
    G[i].emplace_back(i + 10, 1);
  }
  for (int i = A; 0 <= i - 10; i -= 10) {
    G[i].emplace_back(i - 10, 1);
  }
  auto dist = dijkstra(G, A);

  cout << dist[B] << endl;

  return 0;
}