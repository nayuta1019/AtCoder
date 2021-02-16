/**
2018/11/11/	解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}

typedef long long ll;

int main() {
  string S;
  cin >> S;
  int N = S.length();

  ll ans = 0;
  for (int bit = 0; bit < (1 << (N - 1)); bit++) {
    ll sum = 0;
    ll num = S[0] - '0';
    for (int i = 0; i < N - 1; i++) {
      if ((bit >> i) & 1) {
        sum += num;
        num = 0;
      }
      num = num * 10 + S[i + 1] - '0';
    }
    sum += num;

    ans += sum;
  }

  cout << ans << endl;

  return 0;
}