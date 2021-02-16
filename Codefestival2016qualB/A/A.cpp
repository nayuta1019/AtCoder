/*
2019/10/18/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
  cin >> s;
  t = "CODEFESTIVAL2016";
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}