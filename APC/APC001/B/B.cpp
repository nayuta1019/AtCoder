/*
2019/12/03/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> a(N), b(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];

  long long a_sum = 0, b_sum = 0, a_cnt = 0, b_cnt = 0;
  for (int i = 0; i < N; i++) {
    a_sum += a[i], b_sum += b[i];
    if (a[i] < b[i]) {
      a_cnt += (b[i] - a[i]) / 2;
    } else if (a[i] > b[i]) {
      b_cnt += a[i] - b[i];
    }
  }

  if (a_cnt >= b_cnt) {
    puts("Yes");
  } else {
    puts("No");
  }

  return 0;
}