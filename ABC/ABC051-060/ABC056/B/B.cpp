#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int W, a, b, ans;

  cin >> W >> a >> b;

  if(a+W < b){
    ans = b - (a+W);
  }else if(b+W < a){
    ans = a - (b+W);
  }else{
    ans = 0;
  }

  cout << ans << endl;

  return 0;
}
