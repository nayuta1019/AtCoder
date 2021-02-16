#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int X, ans=1;

  cin >> X;

  for(int i = 2; i <= X; i++){
    int t = i;
    if(X < t*t) break;
    while(t <= X) t *= i;
    t /= i;
    if(ans < t) ans = t;
  }

  cout << ans << endl;

	return 0;
}
