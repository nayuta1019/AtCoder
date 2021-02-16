#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t = "AKIHABARA", u = "KIH";
  cin >> s;
  if (t.size() < s.size()) {
    cout << "NO" << endl;
  } else if (t.size() == s.size()) {
    if (s == t) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (s.size() < 5) {
      cout << "NO" << endl;
      return 0;
    }
    string tmp1 = s.substr(0, 3);
    string tmp2 = s.substr(1, 3);
    if (!(tmp1 == u || tmp2 == u)) {
      cout << "NO" << endl;
      return 0;
    }
    bool k = false, I = false, h = false, b = false, r = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'K') k = true;
      if (s[i] == 'I' && k) I = true;
      if (s[i] == 'H' && I) h = true;
      if (s[i] == 'B' && h) b = true;
      if (s[i] == 'R' && b) r = true;

      if (i + 1 >= s.size()) continue;
      string ss = s.substr(i, 2);
      if (ss == "AA") {
        cout << "NO" << endl;
        return 0;
      }
    }
    if (r)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}