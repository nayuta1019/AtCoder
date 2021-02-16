/*
ARC046
2020/01/24/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a != b) {
    if (a < b && a < n)
      cout << "Aoki" << endl;
    else
      cout << "Takahashi" << endl;
  } else {
    if (n % (a + 1) == 0)
      cout << "Aoki" << endl;
    else
      cout << "Takahashi" << endl;
  }

  return 0;
}