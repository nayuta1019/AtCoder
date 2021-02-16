/*
ARC022
2020/02/02/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  bool i = false, c = false, t = false;
  for (int j = 0; j < s.size(); j++) {
    if (s[j] == 'i' || s[j] == 'I') i = true;
    if ((s[j] == 'c' || s[j] == 'C') && i) c = true;
    if ((s[j] == 't' || s[j] == 'T') && i && c) t = true;
  }
  if (t && c && i)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}