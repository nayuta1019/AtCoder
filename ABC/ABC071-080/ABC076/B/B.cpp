#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, K, ans=1;

  cin >> N >> K;

  for(int i = 0; i < N; i++){
    if(ans < K) ans *= 2;
    else ans += K;
  }

  cout << ans << endl;

	return 0;
}
