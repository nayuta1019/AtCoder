/*
ARC008
2019/11/30/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int NAME[27], KIT[27];

int main() {
  int N, M;
  string name, kit;
  cin >> N >> M >> name >> kit;

  for (int i = 0; i < N; i++) {
    int id = name[i] - 'A';
    NAME[id]++;
  }

  for (int i = 0; i < M; i++) {
    int id = kit[i] - 'A';
    KIT[id]++;
  }

  int ans = 1;
  for (int i = 0; i < 26; i++) {
    if (NAME[i] == 0 && KIT[i] == 0) continue;
    if (NAME[i] != 0 && KIT[i] == 0) {
      cout << -1 << endl;
      return 0;
    }

    if (NAME[i] > KIT[i]) {
      int cnt = (NAME[i] + KIT[i] - 1) / KIT[i];
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;

  return 0;
}