/*
ABC117
2019/08/01/ 解説AC
*/
#define _USE_MATH_DEFINES
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

typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vl;
typedef vector<vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  lint K;
  cin >> N >> K;
  vector<lint> A(N);
  rep(i, N) cin >> A[i];

  lint res = 0;
  for (int d = 60; d >= -1; d--) {
    if (d != -1 && !(K & (1LL << d))) continue;

    lint tmp = 0;
    for (int e = 60; e >= 0; e--) {
      lint mask = 1LL << e;
      int num = 0;
      for (int i = 0; i < N; i++)
        if (A[i] & mask) num++;

      if (e > d) {
        if (K & mask)
          tmp += mask * (N - num);
        else
          tmp += mask * num;
      } else if (e == d) {
        tmp += mask * num;
      } else {
        tmp += mask * max(num, N - num);
      }
    }
    res = max(res, tmp);
  }

  cout << res << endl;

  return 0;
}