/*
2019/11/21/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int l;
string s;

int main() {
  cin >> l >> s;

  if (s.size() < l) {
    cout << s << endl;
  } else {
    cout << s.substr(0, l) << endl;
  }

  return 0;
}