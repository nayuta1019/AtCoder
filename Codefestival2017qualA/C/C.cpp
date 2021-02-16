/*
2019/12/31/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int h, w;
char a[110][110];
char al[26];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      al[a[i][j] - 'a']++;
      al[a[i][j] - 'a'] %= 4;
    }
  }

  bool ok = true;
  if (h % 2 == 0 && w % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (al[i] != 0) {
        ok = false;
      }
    }
  } else if (h % 2 == 1 && w % 2 == 1) {
    int two = 0, one = 0;
    for (int i = 0; i < 26; i++) {
      if (al[i] == 1) one++;
      if (al[i] == 2) two++;
      if (al[i] == 3) one++, two++;
    }
    if (1 < one) ok = false;
    if (h / 2 + w / 2 < two) ok = false;

  } else {
    int two = 0;
    for (int i = 0; i < 26; i++) {
      if (al[i] % 2 == 1) ok = false;
      if (al[i] == 2) two++;
    }
    if (h % 2) {
      if (w / 2 < two) ok = false;
    } else {
      if (h / 2 < two) ok = false;
    }
  }

  if (ok)
    puts("Yes");
  else
    puts("No");

  return 0;
}