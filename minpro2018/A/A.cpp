/*
2019/12/25/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s[0] != 'y' || s[1] != 'a' || s[2] != 'h') {
    cout << "NO" << endl;
    return 0;
  }
  if (s[3] != s[4]) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;

  return 0;
}