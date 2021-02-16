/*
2019/11/12/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) {
    puts("Yes");
  } else {
    puts("No");
  }

  return 0;
}