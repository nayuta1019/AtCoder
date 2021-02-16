/*
2019/10/24/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  if (s.size() < 4 || s.substr(0, 4) != "YAKI") {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }

  return 0;
}