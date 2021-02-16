#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, A, B, ans=0;

  cin >> N >> A >> B;

  for(int x = 1; x <= N; x++){
    int s = 0, t = x;
    while(t != 0){
      s += t % 10;
      t = t / 10;
    }
    if(A <= s && s <= B) ans += x;
  }

  cout << ans << endl;

	return 0;
}
