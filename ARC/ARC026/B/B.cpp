/*
ARC026
2020/01/25/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

/* nの約数を列挙 */
vector<long long> divisors(long long n) {
  vector<long long> res;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (n / i == i) continue;  // 上の行で追加済み。
    res.push_back(n / i);
  }
  return res;
}

int main() {
  llint n;
  cin >> n;

  auto v = divisors(n);
  sort(v.begin(), v.end());
  v.pop_back();
  llint ans = 0;
  for (auto &x : v) {
    ans += x;
  }

  if (ans < n) {
    cout << "Deficient" << endl;
  } else if (n < ans) {
    cout << "Abundant" << endl;
  } else {
    cout << "Perfect" << endl;
  }

  return 0;
}