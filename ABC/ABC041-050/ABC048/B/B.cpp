#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long int f(long int n, long int x){
    if(0 <= n){
      return n / x + 1;
    }else{
      return 0;
    }
}

int main(){
  long int a, b, x, ans;

  cin >> a >> b >> x;

  ans = f(b, x) - f(a-1, x);

  cout << ans << endl;

  return 0;

}
