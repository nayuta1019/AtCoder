/*
KUPC2019
2019/10/13/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int N, X;
int a[1010];

int main() {
  cin >> N >> X;
  for (int i = 0; i < N; i++) cin >> a[i];

  int res = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] + X >= *max_element(a, a + N)) res++;
  }

  cout << res << endl;

  return 0;
}