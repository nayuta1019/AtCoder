#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N, M, X, Y, x, y, max_x = -110, min_y = 110;

  cin >> N >> M >> X >> Y;
  for(int i = 0; i < N; i++){
    cin >> x;
    if(max_x < x) max_x = x;
  }
  for(int i = 0; i < M; i++){
    cin >> y;
    if(y < min_y) min_y = y;
  }

  if(max_x < min_y && X < max_x && min_y <= Y) cout << "No War" << endl;
  else cout << "War" << endl;


  return 0;

}
