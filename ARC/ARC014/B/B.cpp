/*
ARC014
2019/12/20/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

map<string, int> a;

int main() {
  int n;
  cin >> n;
  vector<string> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  char p = w[0][0];
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      if (0 < a[w[i]] || p != w[i][0]) {
        cout << "WIN" << endl;
        return 0;
      } else {
        a[w[i]]++;
        p = w[i].back();
      }
    } else {
      if (0 < a[w[i]] || p != w[i][0]) {
        cout << "LOSE" << endl;
        return 0;
      } else {
        a[w[i]]++;
        p = w[i].back();
      }
    }
  }

  cout << "DRAW" << endl;

  return 0;
}