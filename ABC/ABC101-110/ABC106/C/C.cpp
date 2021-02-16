//未完成
#include <iostream>
#include <string>

using namespace std;

int main(){

  long K;
  int flag = 1;
  string S;

  cin >> S >> K;

  if(K == 1){
    cout << S[0] << endl;
    return 0;
  }

  for(int i = 0; i < S.size(); i++){

    if(S[i] != '1') {
      cout << S[i] << endl;
      flag = 0;
      break;
    }else if(K == i){
      cout << S[i] << endl;
      flag = 0;
      break;
    }
  }

  if(flag) cout << "1" << endl;

  return 0;
}
