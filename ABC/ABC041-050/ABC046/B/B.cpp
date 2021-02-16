#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  int N, K, ans;

  cin >> N >> K;

  ans = K * pow(K-1, N-1);

  cout << ans << endl;

  return 0;

}
