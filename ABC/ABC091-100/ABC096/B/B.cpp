#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int num[3], K, ans=0;

  cin >> num[0] >> num[1] >> num[2] >> K;

  sort(num, num+3);

  ans += num[0] + num[1];

  for(int i = 0; i < K; i++) num[2] = num[2]*2;
  ans += num[2];

  cout << ans << endl;

	return 0;
}
