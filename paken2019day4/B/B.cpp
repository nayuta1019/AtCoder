/*
2019/12/29/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 1;
  int cnt = 1;
  while (0 < N) {
    ans += pow(5, cnt);
    cnt++;
    N--;
  }
  cout << ans << endl;

  return 0;
}