#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int A, B, C, X, ans=0;

  cin >> A >> B >> C >> X;

  for(int a = 0; a <= A; a++){
    for(int b = 0; b <= B; b++){
      for(int c = 0; c <= C; c++){
        if(a*500+b*100+c*50 == X) ans++;
      }
    }
  }

  cout << ans << endl;

	return 0;
}
