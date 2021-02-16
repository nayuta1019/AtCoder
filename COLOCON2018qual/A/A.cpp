/*
2019/11/06/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;

  if (a <= s.size() && s.size() <= b) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}