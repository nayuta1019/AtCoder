#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N, x = 0, max_x = 0;
  string S;

  cin >> N >> S;

  for(int i = 0; i < N; i++){
    if(S[i] == 'I') x++;
    else x--;
    if(max_x < x) max_x = x;
  }

  cout << max_x << endl;

  return 0;
}
