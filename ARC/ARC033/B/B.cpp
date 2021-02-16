/*
ARC033
2019/11/03/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int na, nb;
map<int, int> mp;

int main() {
  cin >> na >> nb;
  int x;
  for (int i = 0; i < na; i++) {
    cin >> x;
    mp[x]++;
  }
  for (int i = 0; i < nb; i++) {
    cin >> x;
    mp[x]++;
  }
  auto it = mp.begin();
  int a = 0, b = mp.size();
  while (it != mp.end()) {
    if (1 < it->second) a++;
    it++;
  }

  printf("%.12f\n", (double)a / (double)b);

  return 0;
}