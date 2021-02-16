#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int front = 0, back = 0, ans;
  string s;

  cin >> s;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A'){
      front = i;
      break;
    }
  }

  for(int i = s.size()-1; 0 < i; i--){
    if(s[i] == 'Z'){
      back = i;
      break;
    }
  }

  ans = back - front + 1;

  cout << ans << endl;

  return 0;
}
