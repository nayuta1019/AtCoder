/*
2019/12/27/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  cout << N / 400 + (N % 400 == 0 ? 0 : 1) << endl;

  return 0;
}