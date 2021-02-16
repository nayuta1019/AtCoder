/*
AGC013
2019/08/03/ 自力AC
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
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
  cin >> N;
  vector<int> A(N + 1, 0);
  rep(i, N) cin >> A[i];

  bool iflag = false, dflag = false;
  int ans = 0;

  rep(i, N - 1) {
    if (A[i] < A[i + 1]) {
      if (dflag) {
        ans++;
        dflag = false;
        continue;
      }
      dflag = false;
      iflag = true;
    } else if (A[i] > A[i + 1]) {
      if (iflag) {
        ans++;
        iflag = false;
        continue;
      }
      dflag = true;
      iflag = false;
    }
  }

  cout << ans + 1 << endl;

  return 0;
}