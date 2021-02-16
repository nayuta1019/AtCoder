/*
ARC009
2020/01/08/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, string, string> TP;

int main() {
  map<char, string> b;
  int n;
  for (int i = 0; i < 10; i++) {
    char c;
    cin >> c;
    b[c] = to_string(i);
  }
  cin >> n;
  vector<TP> a;
  for (int i = 0; i < n; i++) {
    string s, t = "";
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      t += b[s[j]];
    }
    a.emplace_back(t.size(), t, s);
  }

  sort(a.begin(), a.end());

  for (auto v : a) {
    int x;
    string y, z;
    tie(x, y, z) = v;
    cout << z << endl;
  }

  return 0;
}