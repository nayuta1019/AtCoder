/*
ABC006
2019/08/27/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
size_t LIS(const vector<T> &A) {
  size_t n = A.size();
  vector<T> L;
  L.push_back(A[0]);
  size_t length = 1;
  for (int i = 1; i < n; i++) {
    if (L[length - 1] < A[i]) {
      L.push_back(A[i]);
      length++;
    } else {
      *lower_bound(L.begin(), L.end(), A[i]) = A[i];
    }
  }

  return length;
}

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];

  cout << n - LIS(c) << endl;

  return 0;
}