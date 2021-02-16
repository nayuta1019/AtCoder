/*
ABC153
2020/02/08/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;
const long long INF = 1e18;

int main() {
  llint n, d, a;
  cin >> n >> d >> a;
  vector<P> monster;
  for (int i = 0; i < n; i++) {
    llint x, h;
    cin >> x >> h;
    monster.emplace_back(x, h);
  }
  sort(monster.begin(), monster.end());
  monster.emplace_back(INF, INF);

  vector<int> range(n);
  int r = 0;
  for (int l = 0; l < n; l++) {
    llint xl = monster[l].first;
    llint xr = monster[r].first;
    while (xr - xl <= 2 * d && r < n) {
      r++;
      xr = monster[r].first;
    }
    range[l] = r - 1;
  }

  llint ans = 0;
  vector<llint> sum(n + 2, 0);
  for (int i = 0; i < n; i++) {
    llint h = monster[i].second;
    if (0 < h - sum[i]) {
      h -= sum[i];
      llint cnt = (h + a - 1) / a;
      int j = range[i];
      sum[i] += a * cnt;
      sum[j + 1] -= a * cnt;
      ans += cnt;
    }
    sum[i + 1] += sum[i];
  }
  cout << ans << endl;

  return 0;
}