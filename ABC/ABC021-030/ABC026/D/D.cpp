/*
ABC026
2019/09/24/ 解説AC
*/
#include <bits/stdc++.h>

#define PI 3.14159265358979

using namespace std;

double A, B, C;

int main() {
  cin >> A >> B >> C;

  double left = 0, right = 1e9;
  for (int i = 0; i < 200; i++) {
    double mid = (left + right) / 2;
    double ft = A * mid + B * sin(C * mid * PI);
    if (ft < 100) {
      left = mid;
    } else {
      right = mid;
    }
  }

  printf("%.11f\n", right);

  return 0;
}