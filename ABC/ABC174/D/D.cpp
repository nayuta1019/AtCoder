#include <bits/stdc++.h>

using namespace std;

int v[202020];

int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      v[i]++;
    }
    v[i + 1] = v[i];
  }
  cout << v[n - 1] - v[v[n - 1] - 1] << endl;

  return 0;
}