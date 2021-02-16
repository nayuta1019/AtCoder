/*
ARC021
2020/02/09/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[5][5];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }
  bool flag = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[i][j] == a[i][j + 1]) flag = true;
      if (a[j][i] == a[j + 1][i]) flag = true;
    }
  }
  if (flag)
    cout << "CONTINUE" << endl;
  else
    cout << "GAMEOVER" << endl;

  return 0;
}