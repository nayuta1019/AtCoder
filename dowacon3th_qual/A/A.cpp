/*
2019/11/05/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << max(a + b - n, 0) << endl;
  return 0;
}