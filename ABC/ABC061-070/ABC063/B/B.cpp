#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  string S;
  char check;
  bool flag = true;

  cin >> S;

  for(int i = 0; i < S.size()-1; i++){
    check = S[i];
    for(int j = i+1; j < S.size(); j++){
      if(check == S[j]){
        flag = false;
        break;
      }
    }
  }

  if(flag) cout << "yes" << endl;
  else cout << "no" << endl;

	return 0;
}
