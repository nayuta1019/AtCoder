#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int sx, sy, tx, ty;

  cin >> sx >> sy >> tx >> ty;


  for(int yu = 0; yu < ty - sy; yu++) cout << "U";
  for(int xr = 0; xr < tx - sx; xr++) cout << "R";
  for(int yd = 0; yd < ty - sy; yd++) cout << "D";
  for(int xl = 0; xl < tx - sx; xl++) cout << "L";

  cout << "L";
  for(int yu = 0; yu < ty - sy + 1; yu++) cout << "U";
  for(int xr = 0; xr < tx - sx + 1; xr++) cout << "R";
  cout << "D";
  cout << "R";
  for(int yd = 0; yd < ty - sy + 1; yd++) cout << "D";
  for(int xl = 0; xl < tx - sx + 1; xl++) cout << "L";
  cout << "U";
  cout << endl;

	return 0;
}
