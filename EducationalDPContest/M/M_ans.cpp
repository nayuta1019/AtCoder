#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
const int MOD = (int)1e9 + 7;

//
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
//

int N, K, A[101];
lint dp[101];

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];



  cout <<  << endl;

  return 0;
}