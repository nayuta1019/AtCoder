#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int N, ans = 1;

  cin >> N;

  while(ans <= N) ans *= 2;
  ans /= 2;

  cout << ans << endl;

	return 0;
}
