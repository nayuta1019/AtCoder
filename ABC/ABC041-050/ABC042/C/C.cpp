#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, K, D[10] = {0};

  cin >> N >> K;
  for(int i = 0; i < K; i++){
    int x;
    cin >> x;
    D[x] = 1;
  }

  int ans = N;
  bool  flag = true;

  while(flag){
    string str = to_string(ans);
    for(int j = 0; j < str.size(); j++){

      if(D[str[j] - '0'] == 1){
        flag = true;
        break;
      }else{
        flag = false;
      }
    }
    ans++;
  }
  ans--;

  cout << ans << endl;


	return 0;
}
