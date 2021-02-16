#include <iostream>

using namespace std;

int main(){

  int N, K, X, Y, total = 0;
  cin >> N >> K >> X >> Y;

  for(int i = 0; i < N; i++){
    if(i < K) total += X;
    else total += Y;
  }

  cout << total << endl;

  return 0;

}
