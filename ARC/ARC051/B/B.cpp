/*
ARC051
2019/12/30/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

// (13,8)->(8,5)->(5,3)->(3,2)->(2,1)->(1,0)

int main() {
  int k;
  cin >> k;
  int a = 2, b = 1;
  for (int i = 0; i + 1 < k; i++) {
    int tmp = b;
    b = a;
    a += tmp;
  }
  cout << a << " " << b << endl;

  return 0;
}