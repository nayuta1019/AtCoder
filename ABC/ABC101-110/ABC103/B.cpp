#include <iostream>
#include <string>

using namespace std;

int main(){

  string S, T;
  char tmp;
  int flag = 1;

  cin >> S;
  cin >> T;

  for(int i = 0; i < S.size(); i++){
    tmp = S[S.size()-1];
    for(int j = S.size(); 0 < j; j--){
      S[j] = S[j-1];
    }
    S[0] = tmp;

    cout << S << endl;

    if(S == T){
      cout << "Yes" << endl;
      flag = 0;
      break;
    }
  }

  if(flag) cout << "No" << endl;

  return 0;

}
