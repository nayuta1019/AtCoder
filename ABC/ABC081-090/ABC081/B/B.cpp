#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, A[201];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int ans=0;
  bool flag = true;
  while(flag){
    for(int i = 0; i < N; i++){
      if(A[i] % 2 == 1) flag = false;
      else A[i] = A[i] / 2;
    }
    ans++;
  }
  ans--;

  cout << ans << endl;

	return 0;
}
