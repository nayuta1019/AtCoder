#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

  int N, K, x[100001], ans=0, s=0, X;

  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> x[i];
  }

  X = x[0];
  for(int i = 0; i < N; i++){
    if(x[i] < 0){
      if(x[i]*(-1) <= X) s = i;
    }else{
      if(x[i] <= X) s = i;
    }
  }
cout << s << endl;
  for(int i = 0; i < K; i++){
    ans += x[s];


  }
  cout << ans << endl;

  return 0;
}
