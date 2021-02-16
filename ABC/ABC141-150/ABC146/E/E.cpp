/*
ABC146
2019/12/26/ 解説AC
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  vector<int> s(n + 1, 0);
  for (int i = 0; i < n; i++) s[i + 1] = (s[i] + a[i]) % k;
  map<int, int> mp;
  long long ans = 0;
  queue<int> q;
  for (int i = 0; i < n + 1; i++) {
    ans += mp[s[i]];
    mp[s[i]]++;
    q.push(s[i]);
    if (q.size() == k) {
      mp[q.front()]--;
      q.pop();
    }
  }
  cout << ans << endl;

  return 0;
}