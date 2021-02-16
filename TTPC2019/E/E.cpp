/*
2019/08/31/ AC
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int c[1010][1010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  if (n % 2 == 0) {
    cout << "No" << endl;
    return 0;
  }
  int cnt = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      c[y][x] = cnt;
      cnt++;
    }
  }

  for (int y = 1, x = 1; y < n; y++, x++) {
    swap(c[y][0], c[0][x]);
  }

  cout << "Yes" << endl;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cout << c[y][x] + 1 << (x != n - 1 ? " " : "");
    }
    cout << endl;
  }

  return 0;
}