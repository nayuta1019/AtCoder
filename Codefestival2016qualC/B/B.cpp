/*
2020/02/10/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int main() {
  int k, t;
  cin >> k >> t;
  priority_queue<P> que;
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    que.emplace(a, i);
  }
  int prev = -1;
  while (1 < que.size()) {
    P p = que.top();
    que.pop();
    P q = que.top();
    que.pop();
    p.first--, q.first--;
    if (p.first != 0) que.emplace(p);
    if (q.first != 0) que.emplace(q);
    prev = q.second;
  }
  if (que.empty()) {
    cout << 0 << endl;
  } else {
    P p = que.top();
    if (p.second == prev) {
      cout << p.first << endl;
    } else {
      cout << p.first - 1 << endl;
    }
  }

  return 0;
}