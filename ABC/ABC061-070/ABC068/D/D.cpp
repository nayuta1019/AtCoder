/*
ABC068
2019/10/14/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

long long int K;

int main() {
  cin >> K;
  long long int a = K / 50, b = K % 50;
  cout << 50 << endl;
  for (int i = 0; i < b; i++) {
    cout << 100 - b + a << " ";
  }
  for (int i = 0; i < 50 - b; i++) {
    cout << 49 - b + a << " ";
  }
  cout << endl;

  return 0;
}