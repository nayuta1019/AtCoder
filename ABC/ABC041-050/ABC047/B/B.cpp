#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int W, H, N, menseki = 0;
  int x[110], y[110], a[110], check[110][110];

  cin >> W >> H >> N;
  for(int i = 0; i < N; i++){
    cin >> x[i] >> y[i] >> a[i];
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      check[i][j] = 0;
    }
  }

  for(int i = 0; i < N; i++){
    switch (a[i]) {
      case 1:
      for(int q = 0; q < x[i]; q++){
        for(int p = 0; p < H; p++){
          check[p][q] = 1;
        }
      }

      break;

      case 2:
      for(int q = x[i]; q < W; q++){
        for(int p = 0; p < H; p++){
          check[p][q] = 1;
        }
      }

      break;

      case 3:
      for(int q = 0; q < W; q++){
        for(int p = 0; p < y[i]; p++){
          check[p][q] = 1;
        }
      }

      break;

      case 4:
      for(int q = 0; q < W; q++){
        for(int p = y[i]; p < H; p++){
          check[p][q] = 1;
        }
      }

      break;

    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      menseki += check[i][j];
      cout << check[i][j];
    }
    cout << endl;
  }

  menseki = W*H - menseki;

  cout << menseki << endl;

  return 0;

}
