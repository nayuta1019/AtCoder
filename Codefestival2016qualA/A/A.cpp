/*
2019/10/15/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, s1, s2;
  cin >> s;
  s1 = s.substr(0, 4);
  s2 = s.substr(4, 8);

  cout << s1 << " " << s2 << endl;

  return 0;
}