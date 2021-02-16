/*
ABC151
2020/01/12/ 自力AC
*/
#include <bits / stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

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
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double pi = 3.14159265358979323846;

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

int h, w;
char s[22][22];
int dist[22][22];

int bfs(int sx, int sy) {
  rep(i, 22) {
    rep(j, 22) { dist[i][j] = INF; }
  }
  queue<P> que;
  dist[sy][sx] = 0;
  que.push(P(sx, sy));
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    rep(i, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if (s[ny][nx] == '#') continue;
      if (dist[ny][nx] <= dist[p.second][p.first] + 1) continue;
      dist[ny][nx] = min(dist[ny][nx], dist[p.second][p.first] + 1);
      que.push(P(nx, ny));
    }
  }

  int ret = 0;
  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') continue;
      ret = max(ret, dist[i][j]);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w;
  rep(i, h) {
    rep(j, w) { cin >> s[i][j]; }
  }

  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') continue;
      ans = max(ans, bfs(j, i));
    }
  }
  cout << ans << endl;

  return 0;
}