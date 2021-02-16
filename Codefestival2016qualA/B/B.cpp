/*
2019/10/16/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int a[101010];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  int res = 0;
  for (int i = 1; i <= N; i++) {
    if (i == a[a[i]]) res++;
  }

  cout << res / 2 << endl;

  return 0;
}