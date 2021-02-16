#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, ans=0;

  cin >> N;

  for(int i = N; i < 1000; i++){
    string str = to_string(i);
    if(str[0] == str[1] && str[1] == str[2]){
      ans = i;
      break;
    }
  }
  cout << ans << endl;

	return 0;
}
