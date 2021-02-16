/*
2019/11/23/ 自力AC
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
const int dx1[] = {0, 0};
const int dy1[] = {-1, 1};  // 上、下

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

int H, W, K;
char cake[333][333];
int ans[333][333];
bool used[333];

void bfs1(int x, int y, int num) {
  queue<P> que;
  que.push(P(x, y));  // start
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    for (int i = 0; i < 2; i++) {
      int nx = p.first + dx1[i];
      int ny = p.second + dy1[i];
      if (nx < 0 || ny < 0 || W <= nx || H <= ny) continue;
      if (cake[ny][nx] == '#') continue;
      if (ans[ny][nx] != 0) continue;
      ans[ny][nx] = num;
      if (nx + 1 < W && used[nx + 1] == false) {
        ans[ny][nx + 1] = num;
      }
      if (0 <= nx - 1 && used[nx - 1] == false) {
        ans[ny][nx - 1] = num;
      }
      que.push(P(nx, ny));
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> H >> W >> K;
  rep(y, H) {
    rep(x, W) {
      cin >> cake[y][x];
      if (cake[y][x] == '#') {
        used[x] = true;
      }
    }
  }

  int num = 1;
  rep(x, W) {
    bool r = false, l = false;
    rep(y, H) {
      if (cake[y][x] == '#') {
        ans[y][x] = num;

        if (0 <= x - 1 && used[x - 1] == false) {
          ans[y][x - 1] = num;
          l = true;
        }
        if (x + 1 < W && used[x + 1] == false) {
          ans[y][x + 1] = num;
          r = true;
        }
        bfs1(x, y, num);
        num++;
      }
    }
    if (l) used[x - 1] = true;
    if (r) used[x + 1] = true;
  }

  rep(y, H) {
    rep(x, W - 1) {
      if (ans[y][x + 1] == 0) {
        ans[y][x + 1] = ans[y][x];
      }
    }
  }

  rep(y, H) {
    for (int x = W - 1; 0 < x; x--) {
      if (ans[y][x - 1] == 0) {
        ans[y][x - 1] = ans[y][x];
      }
    }
  }

  rep(y, H) {
    rep(x, W) { cout << ans[y][x] << (x != W - 1 ? " " : ""); }
    cout << endl;
  }

  return 0;
}
