//20180923未完成
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  string S, T;
  char c, tmp;

  cin >> S >> T;

  for(int i = 0; i < (int)S.size(); i++){
    c = S[i];
    tmp = T[i];
    S[i] = T[i];

    for(int j = 0; j < (int)S.size(); j++){
      if(i!=j && S[j] == tmp) S[j] = c;
    }
    //cout << S << endl;
  }

  //cout << S << endl;
  //cout << T << endl;
  if(S == T) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;

}
