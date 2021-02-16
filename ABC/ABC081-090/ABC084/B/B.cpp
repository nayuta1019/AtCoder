#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int A, B;
  string S;
  bool flag = true;

  cin >> A >> B >> S;

  for(int i = 0; i < S.size(); i++){
    if(i < A){
      if(S[i] == '-') flag = false;

    }else if(A < i){
      if(S[i] == '-') flag = false;

    }else{
      if(S[i] != '-') flag = false;
    }

  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

	return 0;
}
