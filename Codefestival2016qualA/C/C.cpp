/*
2019/10/17/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

string s;
int K;

int main() {
  cin >> s >> K;

  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') continue;
    cnt = 'z' - s[i] + 1;
    if (cnt <= K) {
      s[i] = 'a';
      K -= cnt;
    }
  }

  if (K != 0) {
    K %= 26;
    cnt = 'z' - s.back();
    if (cnt < K) {
      K -= cnt;
      s.back() = 'a' + K;
    } else {
      s.back() = s.back() + K;
    }
  }

  cout << s << endl;

  return 0;
}