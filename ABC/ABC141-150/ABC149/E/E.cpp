/*
ABC149
2020/02/19/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
typedef long long llint;

llint n, m;
vector<llint> a, s;

llint getCount(llint tot) {
  llint ret = 0;
  for (int i = 0; i < n; i++) {
    llint ay = tot - a[i];
    llint idx = lower_bound(a.begin(), a.end(), ay) - a.begin();
    ret += n - idx;
  }
  return ret;
}

llint getSum(llint tot) {
  llint ret = 0;
  for (int i = 0; i < n; i++) {
    llint ay = tot - a[i];
    llint idx = lower_bound(a.begin(), a.end(), ay) - a.begin();
    llint cnt = n - idx;
    ret += (s[n] - s[idx]) + a[i] * cnt;
  }
  return ret;
}

int main() {
  cin >> n >> m;
  a.assign(n, 0);
  s.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    s[i + 1] = a[i] + s[i];
  }

  llint ok = 0, ng = INF;
  while (ok + 1 < ng) {
    llint mid = (ok + ng) / 2;
    if (m <= getCount(mid))
      ok = mid;
    else
      ng = mid;
  }

  llint ans = (m - getCount(ok + 1)) * ok + getSum(ok + 1);
  cout << ans << endl;

  return 0;
}