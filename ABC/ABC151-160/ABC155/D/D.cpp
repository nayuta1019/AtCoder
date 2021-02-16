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
const int INF = (int)1e9;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  llint k;
  cin >> n >> k;
  vector<llint> a_pos, a_neg, a_zero, a(n);
  rep(i, n) {
    cin >> a[i];
    if (a[i] < 0)
      a_neg.emplace_back(a[i]);
    else if (a[i] > 0)
      a_pos.emplace_back(a[i]);
    else
      a_zero.emplace_back(a[i]);
  }

  if (a_neg.size() > 0 && a_pos.size() > 0) {
    sort(all(a_pos));
    reverse(all(a_pos));
    sort(all(a_neg));
    llint pos_sz = a_pos.size();
    llint neg_sz = a_neg.size();
    if (k <= pos_sz * neg_sz) {
      for (int i = 0; i + 1 < neg_sz; i++) {
        if (neg_sz < k) {
          k -= neg_sz;
        } else {
          for (int j = 0; j < pos_sz; j++) {
            k--;
            if (k == 0) {
              cout << a_neg[i] * a_pos[j] << endl;
              return 0;
            }
          }
        }
      }
    } else {
      k -= pos_sz * neg_sz;
      // cout << "k = " << k << endl;
      llint sz = a_zero.size();
      reverse(all(a_pos));
      reverse(all(a_neg));
      // cout << sz * (pos_sz + neg_sz) << endl;
      if (k <= sz * (pos_sz + neg_sz)) {
        cout << 0 << endl;
        return 0;
      }

      k -= sz * (pos_sz + neg_sz);
      priority_queue<llint> que;
      for (int i = 0; i + 1 < neg_sz; i++) {
        for (int j = i + 1; j < neg_sz; j++) {
          que.push(a_neg[i] * a_neg[j]);
        }
      }
      for (int i = 0; i + 1 < pos_sz; i++) {
        for (int j = i + 1; j < pos_sz; j++) {
          que.push(a_pos[i] * a_pos[j]);
        }
      }
      for (int i = 0; i < k; i++) {
        que.pop();
      }
      cout << que.top() << endl;
      return 0;
    }
  } else {
    if (a_neg.size() > 0) {
      for (int i = 0; i < n; i++) {
        a_pos.emplace_back(-a_neg[i]);
      }
    }
    sort(all(a_pos));
    for (int i = 0; i < n; i++) {
      if (n - i - 1 < k) {
        k -= n - i - 1;
      } else {
        for (int j = i + 1; j < n; j++) {
          k--;
          if (k == 0) {
            cout << a_pos[i] * a_pos[j] << endl;
            return 0;
          }
        }
      }
    }
  }

  return 0;
}