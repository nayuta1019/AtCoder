#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int A, B, C, D, ans;

  cin >> A >> B >> C >> D;

  if(C < A){
    if(D < A) ans = 0;
    else if(B < D) ans = B - A;
    else ans = D - A;

  }else if(B < C){
    ans = 0;

  }else{
    if(D < B) ans = D - C;
    else ans = B - C;
  }

  cout << ans << endl;

	return 0;
}
