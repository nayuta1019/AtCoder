/*
ARC035
2020/04/02/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*' || t[i] == '*') continue;
    if (s[i] != t[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}