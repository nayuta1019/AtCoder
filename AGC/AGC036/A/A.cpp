/*
AGC036
2020/02/29/ 解説Ac
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  llint s;
  cin >> s;
  const llint MAX = 1e9;
  llint x1 = 0, y1 = 0, x2 = MAX, y2 = 1, x3, y3;
  x3 = (MAX - s % MAX) % MAX;
  y3 = (s + x3) / MAX;
  printf("%lld %lld %lld %lld %lld %lld\n", x1, y1, x2, y2, x3, y3);
  return 0;
}