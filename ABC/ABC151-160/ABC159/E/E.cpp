#include <bits/stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long llint;
typedef unsigned long long ull;
typedef complex<long double> Complex;
typedef pair<int, int> P;
typedef tuple<int, int, int> TP;
typedef vector<int> vec;
typedef vector<vec> mat;

// constant
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double pi = 3.14159265358979323846;

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

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

char cho[11][1010];
int rui[11][1010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  llint h, w, k;
  cin >> h >> w >> k;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> cho[i][j];
    }
  }

  llint ans = INF;
  for (int bit = 0; bit < 1 << (h - 1); bit++) {
    llint cnt = 0;
    vector<vector<llint>> bl;
    vector<llint> v(w, 0);
    for (int j = 0; j < w; j++) {
      v[j] += (llint)(cho[0][j] - '0');
    }
    for (int i = 0; i < (h - 1); i++) {
      if ((bit >> i) & 1) {
        cnt++;
        bl.emplace_back(v);
        for (int j = 0; j < w; j++) {
          v[j] = 0;
        }
      }
      for (int j = 0; j < w; j++) {
        v[j] += (llint)(cho[i + 1][j] - '0');
      }
    }
    bl.emplace_back(v);

    bool ok = true;
    vector<llint> sum(bl.size(), 0);
    for (int i = 0; i < w; i++) {
      bool check = false;
      for (int j = 0; j < bl.size(); j++) {
        if (ok == false) continue;
        if (check) continue;
        if (sum[j] + bl[j][i] > k) {
          if (sum[j] == 0) ok = false;
          check = true;
          for (int p = 0; p < bl.size(); p++) {
            sum[p] = 0;
          }
        }
        sum[j] += bl[j][i];
      }
      if (check) {
        cnt++;
      }
    }

    if (ok) {
      ans = min(ans, cnt);
    }
  }
  assert(ans != INF);
  cout << ans << endl;

  return 0;
}