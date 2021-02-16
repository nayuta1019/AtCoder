/*
ARC018
2020/02/04/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  double h, b;
  cin >> h >> b;
  h /= 100;
  printf("%.12f\n", b * h * h);

  return 0;
}