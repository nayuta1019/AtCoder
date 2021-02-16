/*
AGC019
2019/10/11/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

string s;
long long int al[26], n, ans;

int main() {
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    al[s[i] - 'a']++;
  }

  ans = n * (n - 1) / 2;
  for (int i = 0; i < 26; i++) {
    ans -= al[i] * (al[i] - 1) / 2;
  }

  cout << ans + 1 << endl;

  return 0;
}