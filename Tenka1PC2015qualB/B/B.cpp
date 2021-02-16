/*
2020/03/16/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int check(string s) {
  int cnt = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '{') cnt++;
    if (s[i] == '}') cnt--;
    if (cnt == 1) {
      if (s[i] == ':') return 1;
      if (s[i] == ',') return 0;
    }
  }
  if (s.size() == 2) return 1;
  return 0;
}

int main() {
  string s;
  cin >> s;

  if (check(s))
    cout << "dict" << endl;
  else
    cout << "set" << endl;

  return 0;
}