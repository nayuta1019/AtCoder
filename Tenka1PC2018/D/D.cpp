/*
Tenka1 Programmer Beginner Contest
2020/01/09/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, sz = 3;
  cin >> n;
  if (n == 1) {
    cout << "Yes" << endl;
    cout << 2 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  bool ng = true;
  for (int i = 3, m = 3; m <= n; i++) {
    if (m == n) {
      ng = false;
      break;
    }
    m += i;
    sz++;
  }
  if (ng) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  cout << sz << endl;
  vector<vector<int>> S(sz);
  S[0].emplace_back(1);
  S[0].emplace_back(3);
  S[1].emplace_back(1);
  S[1].emplace_back(2);
  S[2].emplace_back(2);
  S[2].emplace_back(3);

  int add = 4;
  for (int i = 3; i < sz; i++) {
    for (int j = 0; j < i; j++) {
      S[j].emplace_back(add);
      S[i].emplace_back(add);
      add++;
    }
  }

  for (int i = 0; i < sz; i++) {
    cout << S[i].size() << " ";
    for (auto x : S[i]) cout << x << " ";
    cout << endl;
  }

  return 0;
}