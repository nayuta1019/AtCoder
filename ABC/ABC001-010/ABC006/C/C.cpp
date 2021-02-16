#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, M, a, b, c;
  bool flag = false;;

  cin >> N >> M;

  if(M % 2 == 1) b = 1;
  else b = 0;

  for(a = 0; a <= N; a++){
    c = N - a - b;
    if(c < 0) continue;
    if(2*a + 3*b + 4*c == M){
      flag = true;
      break;
    }
  }

  if(flag) cout << a << " " << b << " " << c << endl;
  else cout << "-1 -1 -1" << endl;

	return 0;
}
