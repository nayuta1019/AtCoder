#include <bits/stdc++.h>

using namespace std;

const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int c[10][10];
int x, y;
string w;

int main() {
  cin >> x >> y >> w;
  x--, y--;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> c[i][j];
    }
  }

  return 0;
}