/*
ARC006
2019/11/29/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, L;
  string s[22];
  cin >> N >> L;
  getline(cin, s[0]);
  for (int i = 0; i < L + 1; i++) {
    getline(cin, s[i]);
  }

  int cur = 0;
  for (int i = 0; i < 2 * N - 1; i += 2) {
    cur++;
    if (s[L][i] == 'o') break;
  }

  for (int i = L - 1; 0 <= i; i--) {
    int id = 2 * cur - 2;
    if (id + 1 < 2 * N - 1 && s[i][id + 1] == '-') {
      cur++;
    } else if (0 < id - 1 && s[i][id - 1] == '-') {
      cur--;
    }
  }

  cout << cur << endl;

  return 0;
}