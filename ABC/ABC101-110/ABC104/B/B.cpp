#include <iostream>
#include <string>

using namespace std;

int main(){

  int c = 0, flag = true;
  string S;

  cin >> S;

  if(S[0] != 'A') flag = false;

  for(int i = 2; i < S.size()-1; i++){
    if(S[i] == 'C') c++;
  }
  if(1 != c) flag = false;

  for(int i = 1; i < S.size(); i++){
    if(S[i] != 'C'){
      if(S[i] <= 90) flag = false;
    }
  }

  if(flag){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }

  return 0;
}
