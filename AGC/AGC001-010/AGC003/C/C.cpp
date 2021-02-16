/*
AGC003
2019/10/07/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> A;
int x[101010];

int main() {
  cin >> N;
  A.assign(N + 1, pair<int, int>());
  int a;
  A[0] = make_pair(0, 0);
  for (int i = 1; i <= N; i++) {
    cin >> a;
    A[i] = make_pair(a, i);
  }
  sort(A.begin(), A.end());

  int res = 0;
  for (int i = 2; i <= N; i += 2) {
    if (A[i].second % 2) res++;
  }

  cout << res << endl;

  return 0;
}