#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N;
  bool flag = false;

  cin >> N;

  for(int i = 0; i <= N/4; i++){
    for(int j = 0; j <= N/7; j++){
      if(N == i*4 + j*7) flag = true;
    }
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

	return 0;
}
