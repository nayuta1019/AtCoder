/*
ABC080
2019/11/25/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, C;
int s[101010], t[101010], c[101010];
int sm[202020];
int tt[202020];

int main() {
  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> s[i] >> t[i] >> c[i];

  for (int i = 1; i <= C; i++) {
    for (int j = 0; j < 202020; j++) tt[j] = 0;

    for (int j = 0; j < N; j++) {
      if (c[j] == i) {
        tt[s[j] * 2 - 1]++;
        tt[t[j] * 2]--;
      }
    }

    for (int j = 1; j < 202020; j++) tt[j] += tt[j - 1];

    for (int j = 0; j < 202020; j++) {
      if (tt[j] > 0) {
        sm[j]++;
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < 202020; j++) {
    ans = max(ans, sm[j]);
  }

  cout << ans << endl;

  return 0;
}