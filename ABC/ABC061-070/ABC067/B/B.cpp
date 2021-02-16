#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int N, K, l[51], ans = 0;

  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> l[i];

  sort(l, l+N);

  for(int i = N-1; N-K-1 < i; i--) ans += l[i];

  cout << ans << endl;

	return 0;
}
