#include <iostream>
#include <climits>

#include <ios>
#include <iomanip>

using namespace std;

int main(){

  int x, y;

  cin >> x >> y;

  if( (x*y)%2 == 0 ){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }


  return 0;

}
