#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  string w;
  char x;
  int count, flag = 1;

  cin >> w;

  for(int i = 0; i < w.size(); i++){
    x = w[i];
    count = 0;
    for(int j = 0; j < w.size(); j++){
      if(x == w[j]) count++;
    }

    if(count % 2 == 1){
      flag = 0;
      break;
    }
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;

}
