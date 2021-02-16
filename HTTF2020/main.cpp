/*
2019/11/02/
*/
#include <bits/stdc++.h>

using namespace std;

struct Pos {
  int x, y;
  char c;
  Pos() { Pos(0, 0, 0); };
  Pos(int ix, int iy, char ic) { x = ix, y = iy, c = ic; };
};
typedef pair<int, int> P;
const int dx[] = {0, 1, 0, -1};  // 0 1 2 3
const int dy[] = {1, 0, -1, 0};  // U R D L
const char dir[] = {'U', 'L', 'D', 'R'};

int N, M, B;
int gy, gx;
vector<Pos> Robot, Block;
char masu[55][55];
char masu2[55][55];

int main() {
  cin >> N >> M >> B >> gy >> gx;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      masu[y][x] = masu2[y][x] = '.';
    }
  }
  masu[gy][gx] = 'G';
  Robot.resize(M);
  Block.resize(B);
  for (int i = 0; i < M; i++) {
    int ry, rx;
    char rc;
    cin >> ry >> rx >> rc;
    Robot[i] = Pos(rx, ry, rc);
  }
  for (int i = 0; i < B; i++) {
    int by, bx;
    cin >> by >> bx;
    masu[by][bx] = 'B';
    Block[i] = Pos(bx, by, 'B');
  }

  queue<P> que;
  que.push(P(gx, gy));
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {  // U R D L
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx < 0 || ny < 0 || N <= nx || N <= ny) continue;
      if (masu[ny][nx] != '.') continue;
      masu[ny][nx] = dir[i];
      que.push(P(nx, ny));
    }
  }

  for (auto r : Robot) {
    int cx = r.x;
    int cy = r.y;
    int px = -1, py = -1;
    if (masu[cy][cx] == r.c) {
      px = cx, py = cy;
    }

    while (!(cx == gx && cy == gy)) {
      if (masu[cy][cx] == 'U') {
        if (masu[py][px] != masu[cy][cx]) {
          masu2[cy][cx] = masu[cy][cx];
        }
        px = cx, py = cy;
        cy--;
      } else if (masu[cy][cx] == 'R') {
        if (masu[py][px] != masu[cy][cx]) {
          masu2[cy][cx] = masu[cy][cx];
        }
        px = cx, py = cy;
        cx++;
      } else if (masu[cy][cx] == 'D') {
        if (masu[py][px] != masu[cy][cx]) {
          masu2[cy][cx] = masu[cy][cx];
        }
        px = cx, py = cy;
        cy++;
      } else if (masu[cy][cx] == 'L') {
        if (masu[py][px] != masu[cy][cx]) {
          masu2[cy][cx] = masu[cy][cx];
        }
        px = cx, py = cy;
        cx--;
      }
      if (cx == r.x && cy == r.y) break;
    }
  }

  vector<Pos> ans;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (masu[y][x] == 'G' || masu[y][x] == 'B') continue;
      if (masu[y][x] == '.') continue;
      if (masu2[y][x] == '.') continue;
      ans.push_back(Pos(x, y, masu2[y][x]));
    }
  }
  /* output */
  cout << ans.size() << endl;
  for (auto v : ans) {
    cout << v.y << " " << v.x << " " << v.c << endl;
  }

  return 0;
}
