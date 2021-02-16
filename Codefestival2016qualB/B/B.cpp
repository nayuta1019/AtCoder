/*
2019/10/19/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, A, B, sum, cnt;
string s, ans[101010];

int main() {
  cin >> N >> A >> B >> s;

  for (int i = 0; i < N; i++) {
    if (s[i] == 'a') {
      if (sum < A + B) {
        sum++;
        ans[i] = "Yes";
      }
    } else if (s[i] == 'b') {
      if (sum < A + B && cnt < B) {
        sum++;
        cnt++;
        ans[i] = "Yes";
      }
    }

    if (ans[i] != "Yes") ans[i] = "No";
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}