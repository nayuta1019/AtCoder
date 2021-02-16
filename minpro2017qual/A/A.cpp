/*
2019/11/02/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int y = 0, a = 0, h = 0, o = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'y') y++;
    if (s[i] == 'a') a++;
    if (s[i] == 'h') h++;
    if (s[i] == 'o') o++;
  }
  if (y == 1 && a == 1 && h == 1 && o == 2) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}