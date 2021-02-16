#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, l[1001], r[1001], ans=0;

  cin >> N;
  for(int i = 0; i < N; i++) cin >> l[i] >> r[i];

  for(int i = 0; i < N; i++) ans += r[i] - l[i] + 1;

  cout << ans << endl;

	return 0;
}
