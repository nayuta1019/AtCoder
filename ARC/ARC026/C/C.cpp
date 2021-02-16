/*
ARC026
2019/11/10/ 解説AC
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

int main() {
  int N, L;
  cin >> N >> L;
  Graph<long long> G(L + 1);
  int l, r;
  long long c;
  for (int i = 1; i <= L; i++) G[i].emplace_back(i - 1, 0);
  for (int i = 0; i < N; i++) {
    cin >> l >> r >> c;
    G[l].emplace_back(r, c);
  }

  auto dist = dijkstra(G, 0);

  cout << dist[L] << endl;

  return 0;
}