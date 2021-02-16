#include <iostream>
#include <climits>
#include <string>

#include <ios>
#include <iomanip>

using namespace std;

int main(){

  int N, b, flag = 1;
  string W[110];

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> W[i];
  }

  for(int i = 0; i < N-1; i++){
    for(int j = i+1; j < N; j++){
      if(W[i] == W[j]){
        flag = 0;
        break;
      }
    }
  }

  for(int i = 1; i < N; i++){
    b = W[i-1].size();
    if(W[i-1][b-1] != W[i][0]){
      flag = 0;
      break;
    }
  }



  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}
