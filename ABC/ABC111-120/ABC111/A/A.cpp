#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  string str;

  cin >> str;

  for(int i = 0; i < 3; i++){
    if(str[i] == '1') str[i] = '9';
    else str[i] = '1';

  }

  cout << str << endl;


	return 0;
}
