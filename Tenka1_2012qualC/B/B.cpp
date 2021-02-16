/*
2020/03/30/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> P;
string s;
vector<P> v;

vector<P> func(char c) {
  vector<P> ret;
  vector<bool> w(5, 0);
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first == c) {
      if (v[i].second == 1) {
        w[0] = 1;
      } else if (v[i].second == 10) {
        w[1] = 1;
      } else if (v[i].second == 11) {
        w[2] = 1;
      } else if (v[i].second == 12) {
        w[3] = 1;
      } else if (v[i].second == 13) {
        w[4] = 1;
      } else {
        ret.emplace_back(v[i]);
      }
    } else {
      ret.emplace_back(v[i]);
    }
    if (w[0] && w[1] && w[2] && w[3] && w[4]) break;
  }
  return ret;
}

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    int num;
    char c = s[i];
    char d = s[i + 1];
    if (d == 'J') {
      num = 11;
    } else if (d == 'Q') {
      num = 12;
    } else if (d == 'K') {
      num = 13;
    } else if (d == 'A') {
      num = 1;
    } else if (d == '1') {
      num = 10;
      i++;
    } else {
      num = (d - '0');
    }
    v.emplace_back(c, num);
    i++;
  }

  vector<vector<P>> ans(4);
  vector<pair<int, int>> n(4);
  ans[0] = func('S');
  ans[1] = func('H');
  ans[2] = func('D');
  ans[3] = func('C');
  n[0] = make_pair(ans[0].size(), 0);
  n[1] = make_pair(ans[1].size(), 1);
  n[2] = make_pair(ans[2].size(), 2);
  n[3] = make_pair(ans[3].size(), 3);
  sort(n.begin(), n.end());
  if (ans[n[0].second].size() == 0) {
    cout << 0 << endl;
  } else {
    for (auto &w : ans[n[0].second]) {
      cout << w.first;
      if (w.second == 1) {
        cout << 'A';
      } else if (w.second == 11) {
        cout << 'J';
      } else if (w.second == 12) {
        cout << 'Q';
      } else if (w.second == 13) {
        cout << 'K';
      } else {
        cout << w.second;
      }
    }
    cout << endl;
  }

  return 0;
}