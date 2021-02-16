#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main(){
  int A, B, C, ans;

  cin >> A >> B >> C;

  if( A == max({A, B, C}) ){
      ans = 10*A;
      ans += B + C;
  }else if(B == max({A, B, C}) ){
      ans = 10*B;
      ans += A + C;
  }else{
      ans = 10*C;
      ans += A + B;
  }


  cout << ans << endl;

  return 0;

}
