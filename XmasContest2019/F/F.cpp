#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
const int INF = 1e9;
bool used[4];

int h, w;
string s[1010];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  P lu, ru, ld, rd;                 // (x, y)
  lu.first = INF, lu.second = INF;  // 0
  ld.first = INF, ld.second = -1;   // 1
  ru.first = -1, ru.second = INF;   // 2
  rd.first = -1, rd.second = -1;    // 3

  for (int i = 0; i < h / 2; i++) {
    for (int j = 0; j < w / 2; j++) {
      if (s[i][j] == '.') {
        lu.first = min(lu.first, j);
        lu.second = min(lu.second, i);
        used[0] = true;
      }
    }
  }

  for (int i = h - 1; h / 2 - 1 < i; i--) {
    for (int j = 0; j < w / 2; j++) {
      if (s[i][j] == '.') {
        ld.first = min(ld.first, j);
        ld.second = max(ld.second, i);
        used[1] = true;
      }
    }
  }

  for (int i = 0; i < h / 2; i++) {
    for (int j = w - 1; w / 2 - 1 < j; j--) {
      if (s[i][j] == '.') {
        ru.first = max(ru.first, j);
        ru.second = min(ru.second, i);
        used[2] = true;
      }
    }
  }

  for (int i = h - 1; h / 2 - 1 < i; i--) {
    for (int j = w - 1; w / 2 - 1 < j; j--) {
      if (s[i][j] == '.') {
        rd.first = max(rd.first, j);
        rd.second = max(rd.second, i);
        used[3] = true;
      }
    }
  }

  cout << "before\n";
  cout << lu.first << " " << lu.second << endl;
  cout << ld.first << " " << ld.second << endl;
  cout << ru.first << " " << ru.second << endl;
  cout << rd.first << " " << rd.second << endl;

  if (used[1]) {
    ld.second = ld.second - h / 2 + 1;
  }
  if (used[2]) {
    ru.first = ru.first - w / 2 + 1;
  }
  if (used[3]) {
    rd.first = rd.first - w / 2 + 1;
    rd.second = rd.second - h / 2 + 1;
  }
  cout << "after\n";
  cout << lu.first << " " << lu.second << endl;
  cout << ld.first << " " << ld.second << endl;
  cout << ru.first << " " << ru.second << endl;
  cout << rd.first << " " << rd.second << endl;

  

  return 0;
}