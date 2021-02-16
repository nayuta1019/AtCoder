/*
2019/06/29
*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}

typedef long long ll;

int main() {
  int x, y;
  int g[] = {0, 1, 2, 1, 3, 1, 3, 1, 1, 3, 1, 3, 1};
  cin >> x >> y;
  if (g[x] == g[y])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}