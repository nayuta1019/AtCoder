/*
ARC003
2019/11/18/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    reverse(s[i].begin(), s[i].end());
  }

  sort(s.begin(), s.end());

  for (int i = 0; i < n; i++) {
    reverse(s[i].begin(), s[i].end());
    cout << s[i] << endl;
  }

  return 0;
}