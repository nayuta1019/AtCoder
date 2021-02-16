#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  string S;
  int al[27] = {0}, c;
  char ans;
  bool flag = false;

  cin >> S;

  for(int i = 0; i < S.size(); i++){
    c = S[i] - 'a';
    al[c]++;
  }


  for(int i = 0; i < 26; i++){
    if(al[i] == 0){
        ans = i + 'a';
        flag = true;
        break;
    }
  }

  if(flag) cout << ans << endl;
  else cout << "None" << endl;

	return 0;
}
