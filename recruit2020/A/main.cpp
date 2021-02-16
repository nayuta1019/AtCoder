#include <bits/stdc++.h>

using namespace std;

const int H_MAX = 1010;

int N, W, K, V;
vector<int> color, value, ans;
int grid[H_MAX][10];  // モノミノのid
int max_cost = 0, res_lim;

int calc_cost() {
  int cost = 0;
  for (int y = 0; y < H_MAX; y++) {
    vector<int> c(K, 0);
    bool ok = true;
    for (int x = 0; x < W; x++) {
      int mm_id = grid[y][x];
      if (mm_id < 0) {
        ok = false;
        continue;
      }
      c[color[mm_id]] += value[mm_id];
    }
    if (ok) cost += *max_element(c.begin(), c.end());
  }
  return cost;
}

void func(const int &base_color, const int &W_LIM, const int &lim) {
  // init grid
  for (int y = 0; y < H_MAX; y++) {
    for (int x = 0; x < W; x++) {
      grid[y][x] = -1;
    }
  }

  vector<int> simu(N, -1);  //モノミノを積んだ列番号
  queue<int> que;
  int row = 0, bh = 0, h = 0, w_lim = W_LIM;
  // base_colorの落とす列を決める
  for (int i = 0; i < N; i++) {
    if (i >= lim) break;
    if (color[i] == base_color) {
      simu[i] = row;
      grid[bh][row] = i;
      row++;
      if (row == W_LIM) row = 0, bh++;
    } else {
      simu[i] = w_lim;
      grid[h][w_lim] = i;
      w_lim++;
      if (w_lim == W) w_lim = W_LIM, h++;
    }
  }

  // 他の色の落とす位置を決める
  int mm_id = lim;
  bool fin = false;
  for (int y = 0; y < H_MAX; y++) {
    if (fin) break;
    for (int x = 0; x < W; x++) {
      if (fin) break;
      int check = grid[y][x];
      if (check >= 0) continue;
      simu[mm_id] = x;
      grid[y][x] = mm_id;
      mm_id++;
      if (mm_id == N) {
        fin = true;
      }
    }
  }

  int ret_cost = calc_cost();
  if (max_cost < ret_cost) {
    max_cost = ret_cost;
    ans = simu;
    res_lim = lim;
  }
}

void simulate() {
  for (int lim = 100; lim < N; lim++) {
    for (int W_LIM = 1; W_LIM < W; W_LIM++) {
      for (int i = 0; i < K; i++) {
        func(i, W_LIM, lim);
      }
    }
  }
}

void input() {
  cin >> N >> W >> K >> V;
  color.assign(N, 0);
  value.assign(N, 0);
  ans.assign(N, 0);
  for (int i = 0; i < N; i++) cin >> color[i] >> value[i];
}

void output() {
  for (int i = 0; i < N; i++) cout << ans[i] << endl;
}

int main() {
  input();
  simulate();
  output();
  cout << max_cost << endl;
  cout << res_lim << endl;

  return 0;
}