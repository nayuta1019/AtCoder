#include <bits/stdc++.h>

using namespace std;

int N;
long long int H[101010], S[101010];

bool check(long long int mid) {
  vector<long long int> t;
  for (int i = 0; i < N; i++) {
    if (mid - H[i] < 0) return false;
    t.push_back((mid - H[i]) / S[i]);
  }
  sort(t.begin(), t.end());
  for (int i = 0; i < N; i++) {
    if (t[i] < i) return false;
  }
  return true;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> H[i] >> S[i];

  long long int left = 0, right = 1e18;
  while (left + 1 < right) {
    long long int mid = (left + right) / 2;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << right << endl;

  return 0;
}