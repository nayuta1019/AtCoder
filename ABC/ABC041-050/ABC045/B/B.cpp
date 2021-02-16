#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

  char next;
  string S_A, S_B, S_C;
  vector<char> A, B, C;

  cin >> S_A >> S_B >> S_C;

  for(int i = S_A.size()-1; 0 <= i ; i--) A.push_back(S_A[i]);
  for(int i = S_B.size()-1; 0 <= i ; i--) B.push_back(S_B[i]);
  for(int i = S_C.size()-1; 0 <= i ; i--) C.push_back(S_C[i]);

  next = A[S_A.size()-1];
  A.pop_back();

  while(1){
    if(next == 'a'){
      if(A.empty()){
        cout << "A" << endl;
        break;
      }
      next = A[A.size()-1];
      A.pop_back();

    }else if(next == 'b'){
      if(B.empty()){
        cout << "B" << endl;
        break;
      }
      next = B[B.size()-1];
      B.pop_back();

    }else if(next == 'c'){
      if(C.empty()){
        cout << "C" << endl;
        break;
      }
      next = C[C.size()-1];
      C.pop_back();

    }

  }

  return 0;

}
