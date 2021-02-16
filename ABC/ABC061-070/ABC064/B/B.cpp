#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int N, a[110], ans;

  cin >> N;
  for(int i = 0; i < N; i++) cin >> a[i];

  sort(a, a+N);

  ans = a[N-1] - a[0];

  cout << ans << endl;

	return 0;
}
