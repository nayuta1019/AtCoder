/*
2019/11/22/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

string s;
int al[27];

int main() {
  cin >> s;
  int N = s.size();
  for (int i = 0; i < N; i++) al[s[i] - 'a']++;

  int odd = 0;
  for (int i = 0; i < 26; i++) {
    if (al[i] == 0) continue;
    if (al[i] % 2) odd++;
  }

  if (odd == 0) {
    cout << N << endl;
  } else {
    int t = (N - odd) / (2 * odd);
    cout << 2 * t + 1 << endl;
  }

  return 0;
}