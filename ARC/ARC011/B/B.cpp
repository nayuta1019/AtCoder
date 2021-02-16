/*
ARC011
2020/01/06/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int al[27] = {-1, 1,  1, 2, -1, 4, 9, 8,  -1, 3, 8, 5,  7,
              9,  -1, 7, 4, 0,  6, 3, -1, 5,  2, 6, -1, 0};

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];

  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    vector<int> ans;
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '.' || s[i][j] == ',') continue;
      if (s[i][j] < 'a') s[i][j] += 32;
      int id = s[i][j] - 'a';
      int num = al[id];
      if (num != -1) ans.emplace_back(num);
    }
    if (!ans.empty()) {
      v.emplace_back(ans);
    }
  }

  for (int i = 0; i < v.size(); i++) {
    for (auto x : v[i]) {
      cout << x;
    }
    if (i + 1 != v.size()) cout << " ";
  }
  cout << endl;

  return 0;
}