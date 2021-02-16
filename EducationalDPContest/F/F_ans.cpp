/*
2019/08/02/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const long long INF = 1LL << 60;

string s, t;
int dp[3100][3100];

int main() {
  cin >> s >> t;

  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < t.size(); j++) {
      if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  string res = "";
  int i = (int)s.size(), j = (int)t.size();

  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {  //(i-1, j) -> (i, j)と更新されていた場合
      i--;                           // DPの遷移を遡る
    } else if (dp[i][j] ==
               dp[i][j - 1])  //(i,j-1) -> (i, j)と更新されていた場合
      j--;                    // DPの遷移を遡る
    else {                    //(i-1, j-1)->(i, j)と更新されていた場合
      res =
          s[i - 1] + res;  //このときs[i-1] == t[j-1]なので、t[j-1] + res でもOK
      i--, j--;            // DPの遷移を遡る
    }
  }

  cout << res << endl;

  return 0;
}