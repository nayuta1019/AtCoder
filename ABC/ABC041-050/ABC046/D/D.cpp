/*
ABC046
2019/08/23/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int p = 0, g = 0;
  rep(i, n) if (s[i] == 'p') p++;

  cout << n / 2 - p << endl;

  return 0;
}