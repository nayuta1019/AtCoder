#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, ans=1;

  cin >> N;

  for(int i = 1; i < N; i++){
    ans = i * i;
    if(N < ans){
      ans = (i - 1) * (i - 1);
      break;
    }
  }

  cout << ans << endl;

	return 0;
}
