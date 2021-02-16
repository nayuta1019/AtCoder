#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int A, B, ans=0;
  string str;

  cin >> A >> B;

  for(int i = A; i <= B; i++){
    bool flag = true;
    str = to_string(i);

    for(int j = 0; j < str.size(); j++){
      if(str.size()-j < j) break;
      if(str[j] != str[str.size()-1-j]){
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  }

  cout << ans << endl;

	return 0;
}
