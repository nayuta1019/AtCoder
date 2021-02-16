#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int K, S, count=0;

  cin >> K >> S;

  for(int x = 0; x <= K; x++){
    for(int y = 0; y <= K; y++){
      int z = S - x - y;
      if(0 <= z && z <= K) count++;
    }
  }

  cout << count << endl;

  return 0;
}
