#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, S;

  cin >> N;

  int t = N % 10;
  int s = N / 10;
  S = t;
  while(s != 0){
    int tmp = s;
    t = s % 10;
    S += t;
    s = tmp / 10;
  }
  
  if(N % S == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

	return 0;
}
