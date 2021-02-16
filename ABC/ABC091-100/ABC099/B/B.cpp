#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int a, b, ans=0;

  cin >> a >> b;

  int x = b - a;

  for(int i = 1; i < x; i++){
    ans += i;
  }

  ans -= a;

  cout << ans << endl;

	return 0;
}
