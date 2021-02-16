#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  string S, str1, str2;
  int size;

  cin >> S;

  while(1){
    S.pop_back(); S.pop_back();
    size = S.size();
    str1 = S.substr(0, size/2);
    str2 = S.substr(size/2, size/2);
    if(str1 == str2) break;
  }

  cout << size << endl;

	return 0;
}
