#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int x[4], y[4];

  for(int i = 0; i < 2; i++) cin >> x[i] >> y[i];

  x[2] = x[1]-(y[1] - y[0]);
  x[3] = x[2] - (x[1] - x[0]);
  y[2] = y[1] + (x[1] - x[0]);
  y[3] = y[0] + (x[1] - x[0]);

  cout << x[2] << " " << y[2] << " " << x[3] << " " << y[3] << endl;

	return 0;
}
