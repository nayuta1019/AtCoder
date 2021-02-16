/*
ABC148
2019/12/23/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;

  long long ans = 0;
  if (n % 2 == 0) {
    for (long long i = 5; i <= n; i *= 5) {
      ans += n / (i * 2);
    }
  }
  cout << ans << endl;
  return 0;
}