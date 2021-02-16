/*
2019/11/19/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() < 5) {
    puts("No");
    return 0;
  }
  string tmp = s.substr(0, 5);
  if (tmp == "MUJIN") {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}