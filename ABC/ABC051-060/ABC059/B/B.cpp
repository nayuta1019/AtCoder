#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  string A, B;

  cin >> A >> B;

  if(A == B){
    cout << "EQUAL" << endl;
  }else{
    if(A.size() < B.size()){
      cout << "LESS" << endl;
    }else if(A.size() > B.size()){
      cout << "GREATER" << endl;
    }else{
      for(int i = 0; i < A.size(); i++){
        if(A[i] < B[i]){
          cout << "LESS" << endl;
          break;
        }else if(A[i] > B[i]){
          cout << "GREATER" << endl;
          break;
        }
      }
    }
  }

  return 0;
}
