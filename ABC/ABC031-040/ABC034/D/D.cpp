/*
ABC034
2019/09/24/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, K;
double w[1010], p[1010];

bool check(double mid) {
  vector<double> v;
  for (int i = 0; i < N; i++) v.push_back((p[i] - mid) * w[i]);
  sort(v.rbegin(), v.rend());
  double sum = 0;
  for (int i = 0; i < K; i++) sum += v[i];
  return sum >= 0;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> w[i] >> p[i];

  double left = 0, right = 100;
  for (int i = 0; i < 200; i++) {
    double mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }

  printf("%.11f\n", right);

  return 0;
}