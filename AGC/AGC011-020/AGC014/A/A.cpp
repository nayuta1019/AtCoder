/*
AGC014
2019/08/04/ 解説AC
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

  int A, B, C;
  cin >> A >> B >> C;

  int ans = 0;
  while (!(A % 2 || B % 2 || C % 2)) {
    ans++;
    int at = (B + 1) / 2 + C / 2;
    int bt = A / 2 + (C + 1) / 2;
    int ct = (A + 1) / 2 + B / 2;

    if (A == B && B == C) {
      if (A % 2 == 0) {
        cout << -1 << endl;
        return 0;
      }
    }

    A = at;
    B = bt;
    C = ct;
  }

  cout << ans << endl;

  return 0;
}