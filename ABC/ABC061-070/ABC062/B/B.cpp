#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int H, W;
  char a[110][110];

  cin >> H >> W;
  for(int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
      cin >> a[y][x];
    }
  }

  for(int i = 0; i < W+2; i++) cout << "#";
  cout << endl;

  for(int y = 0; y < H; y++){
    cout << "#";
    for(int x = 0; x < W; x++){
      cout << a[y][x];
    }
    cout << "#" << endl;
  }

  for(int i = 0; i < W+2; i++) cout << "#";
  cout << endl;

	return 0;
}
