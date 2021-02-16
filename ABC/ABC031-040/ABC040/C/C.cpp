#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, a[100000], dp[100000] = {0};

  cin >> N;
  for(int i = 0; i < N; i++) cin >> a[i];

  for(int i = 1; i < N; i++){

    if(i < 2){
      dp[i] = abs(a[i-1] - a[i]);
      continue;
    }

    int x, y;

    x = dp[i-2] + abs(a[i-2] - a[i]);
    y = dp[i-1] + abs(a[i-1] - a[i]);

    if(x < y) dp[i] = x;
    else dp[i] = y;

  }

  cout << dp[N-1] << endl;

	return 0;
}
