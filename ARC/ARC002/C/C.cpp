/*
ARC002
2019/12/18/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
char com[] = {'A', 'B', 'X', 'Y'};

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = INF;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      string L = "";
      L += com[i];
      L += com[j];
      for (int p = 0; p < 4; p++) {
        for (int q = 0; q < 4; q++) {
          string R = "";
          R += com[p];
          R += com[q];
          if (L == R) continue;
          int cnt = 0, ok = 0;
          for (int i = 0; i + 1 < n; i++) {
            string c = "";
            c += s[i];
            c += s[i + 1];
            if (L == c && ok == 0) {
              cnt++;
              ok = 2;
            }
            if (R == c && ok == 0) {
              cnt++;
              ok = 2;
            }
            if (ok != 0) ok--;
          }

          ans = min(ans, n - cnt);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}