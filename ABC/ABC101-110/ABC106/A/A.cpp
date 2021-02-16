#include <iostream>
#include <string>

using namespace std;

int main(){

  int A, B, ans;

  cin >> A >> B;

  ans = A * B;
  ans = ans - A - B - A*B;

  cout << ans << endl;

  return 0;
}
