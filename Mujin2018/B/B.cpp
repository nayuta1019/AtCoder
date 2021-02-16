/*
2019/11/20/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int a;
string s;

int main() {
  cin >> a >> s;
  if (a == 0) {
    puts("Yes");
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+')
      a++;
    else {
      a--;
      if (a <= 0) {
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");

  return 0;
}