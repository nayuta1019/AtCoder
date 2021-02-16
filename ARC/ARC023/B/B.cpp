/*
ARC023
2020/01/23/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

const int INF = 1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int h, w, d;
int a[1010][1010], dist[1010][1010];

int main() {
  cin >> h >> w >> d;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      cin >> a[y][x];
      dist[y][x] = INF;
    }
  }

  queue<P> que;
  que.emplace(0, 0);
  dist[0][0] = 0;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx < 0 || ny < 0 || w <= nx || h <= ny) continue;
      if (dist[ny][nx] <= dist[p.second][p.first] + 1) continue;
      dist[ny][nx] = dist[p.second][p.first] + 1;
      que.emplace(nx, ny);
    }
  }

  int ans = 0;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      dist[y][x] = d - dist[y][x];
      if (dist[y][x] < 0) continue;
      if (dist[y][x] % 2) continue;
      ans = max(ans, a[y][x]);
    }
  }

  cout << ans << endl;

  return 0;
}