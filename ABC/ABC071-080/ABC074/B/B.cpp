#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, K, x[110], ans = 0;

  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> x[i];

  for(int i = 0; i < N; i++){
    if(x[i] < K - x[i]) ans += x[i] * 2;
    else ans += (K - x[i]) * 2;
  }
  cout << ans << endl;

	return 0;
}
