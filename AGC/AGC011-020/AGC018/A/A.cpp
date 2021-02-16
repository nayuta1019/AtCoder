/*
AGC018
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

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  ll g = 0, m = 0;
  rep(i, N) {
    ll A;
    cin >> A;
    if (g == 0)
      g = A;
    else
      g = gcd(g, A);
    m = max(m, A);
  }

  if (K % g == 0 && K <= m)
    cout << "POSSIBLE\n";
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}