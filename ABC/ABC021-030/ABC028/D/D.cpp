/*
ABC028
2019/11/05/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

long long N, K;

int main() {
  cin >> N >> K;
  double ans = (K - 1) * (N - K) * 6 + (N - 1) * 3 + 1;
  printf("%.12f\n", ans / (double)(N * N * N));

  return 0;
}