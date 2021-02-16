#include <iostream>
using namespace std;

int main(){

  int N, a, b, x, r, tmp;

  cin >> N;

  a = 2;
  b = N;

  if(b == 1){
    tmp = a;
    a = b;
    b = tmp;
  }

  x = a * b;
  r = a % b;
  while(r != 0){
    a = b;
    b = r;
    r = a % b;
  }

  cout << x/b << endl;

  return 0;
}
