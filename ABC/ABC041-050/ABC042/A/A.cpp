#include <iostream>

using namespace std;

int main(){

  int N, f = 0, s = 0;

  for(int i = 0; i < 3; i++){
    cin >> N;
    if(N == 5) f++;
    else s++;
  }

  if(f == 2 && s == 1) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;

}
