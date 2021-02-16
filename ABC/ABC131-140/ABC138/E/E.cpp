/*
ABC138
2019/08/18/ 未完成

contest
conteest
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

string s, t;
int id[27];
vector<int> seq;
vector<int> al[27];

int main() {
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    al[c].emplace_back(i + 1);
  }

  for (int i = 0; i < t.size(); i++) {
    int c = t[i] - 'a';
    if (al[c].empty()) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0; i < 27; i++) {
    al[i].emplace_back(INF);
  }

  seq.push_back(0);
  for (int i = 0; i < t.size(); i++) {
    int c = t[i] - 'a';
    int j = id[c];
    int num =
        lower_bound(al[c].begin() + j, al[c].end(), seq.back()) - al[c].begin();
    if (seq.back() >= al[c][num] || al[c][num] == INF) {
      memset(id, 0, sizeof(id));
      num = 0;
    }
    seq.emplace_back(al[c][num]);
    id[c]++;
  }

  for (auto& x : seq) {
    cout << x << endl;
  }

  long long cnt = 0;
  for (int i = 0; i + 1 < seq.size(); i++) {
    if (seq[i] >= seq[i + 1]) cnt++;
  }

  long long sz = s.size();
  long long b = seq.back();
  long long ans = sz * cnt + b;
  cout << ans << endl;

  return 0;
}