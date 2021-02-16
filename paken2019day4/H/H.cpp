#include <bits/stdc++.h>

using namespace std;

typedef tuple<string, int, int> TP;

int main() {
  int N;
  cin >> N;
  vector<TP> s;
  for (int i = 0; i < N; i++) {
    string in;
    int pos = 0, r = 0;
    cin >> in;
    for (int j = 0; j < in.size(); j++) {
      if (in[j] == '1') break;
      pos++;
    }
    s.emplace_back(in, pos);
  }

  for (auto x : s) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}