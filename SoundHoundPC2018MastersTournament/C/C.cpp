/*
2019/10/10/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

long long int n, m, d;

int main() {
  cin >> n >> m >> d;
  long long int cnt = 2 * (n - d);
  if (d == 0) cnt = n;

  printf("%.11f\n", (double)cnt * (m - 1) / (n * n));

  return 0;
}