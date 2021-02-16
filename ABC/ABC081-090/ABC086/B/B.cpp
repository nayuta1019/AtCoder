#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  string a, b, ab;
  istringstream ss;
  int a_b;
  bool flag = false;

  cin >> a >> b;

  ab = a + b;

  // int x = stoi (a+b); でもOK
  ss = istringstream(ab);
  ss >> a_b;

  for(int i = 1; i < a_b; i++){
    if(a_b == i*i){
      flag = true;
      break;
    }
    if(a_b < i*i) break;
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

	return 0;
}
