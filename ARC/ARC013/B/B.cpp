/*
ARC013
2019/11/23/ 自力AC
*/
#include <bits/stdc++.h>

using namespace std;

int C;
vector<int> v[110];

int main() {
  cin >> C;
  int N, M, L;
  for (int i = 0; i < C; i++) {
    cin >> N >> M >> L;
    v[i].push_back(N);
    v[i].push_back(M);
    v[i].push_back(L);
    sort(v[i].begin(), v[i].end());
  }
  N = 0, M = 0, L = 0;
  for (int i = 0; i < C; i++) {
    N = max(N, v[i][0]);
    M = max(M, v[i][1]);
    L = max(L, v[i][2]);
  }

  cout << N * M * L << endl;

  return 0;
}