/*
ABC0134
2019/07/20/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> b(n + 1, 0);
  for (int i = n; 0 < i; i--) {
    int c = 0;
    for (int j = 2 * i; j <= n; j += i) {
      if (b[j]) c ^= 1;
    }
    if (a[i] != c) b[i] = 1;
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (b[i]) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i != (int)ans.size() - 1 ? " " : "");
  }
  cout << endl;
}