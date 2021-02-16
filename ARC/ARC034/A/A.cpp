/*
ARC034
2020/04/01/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  double res = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    double ans = a + b + c + d;
    ans += (double)(e * (double)110 / 900);
    res = max(res, ans);
  }
  printf("%.12f\n", res);

  return 0;
}