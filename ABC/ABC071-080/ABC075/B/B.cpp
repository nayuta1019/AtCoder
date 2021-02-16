#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int H, W, c;
  char S[55][55], ans[51][51];

  cin >> H >> W;

  for(int y = 0; y < H+2; y++){
    for(int x = 0; x < W+2; x++){
      S[y][x] = '0';
    }
  }

  for(int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
      cin >> S[y+1][x+1];
    }
  }

  for(int y = 1; y < H+1; y++){
    for(int x = 1; x < W+1; x++){
      if(S[y][x] == '#'){
        ans[y-1][x-1] = '#';
        continue;
      }
      c = 0;
      if(S[y-1][x-1] == '#') c++;
      if(S[y-1][x] == '#') c++;
      if(S[y-1][x+1] == '#') c++;
      if(S[y][x-1] == '#') c++;
      if(S[y][x+1] == '#') c++;
      if(S[y+1][x-1] == '#') c++;
      if(S[y+1][x] == '#') c++;
      if(S[y+1][x+1] == '#') c++;
      ans[y-1][x-1] = '0' + c;
    }
  }

  for(int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
      cout << ans[y][x];
    }
    cout << endl;
  }

	return 0;
}
