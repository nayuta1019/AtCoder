/*
2019/10/21/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  bool c = false, f = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'C') c = true;
    if (s[i] == 'F' && c) f = true;
  }

  if (c && f)
    puts("Yes");
  else
    puts("No");

  return 0;
}