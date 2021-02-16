#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int H, W;
  string C[110];

  cin >> H >> W;

  for(int i = 0; i < H; i++) cin >> C[i];

  for(int i = 0; i < 2 * H; i++) cout << C[i/2] << endl;

  return 0;
}
