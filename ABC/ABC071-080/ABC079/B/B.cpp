#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  long int N, Ln, Ln1, Ln2, tmp;

  cin >> N;

  for(int i = 0; i <= N; i++){
    if(i == 0) Ln2 = 2;
    else if(i == 1){
        Ln = 1;
        Ln1 = 1;
    }else{
      Ln = Ln2 + Ln1;
      tmp = Ln1;
      Ln1 = Ln;
      Ln2 = tmp;
    }
  }

  cout << Ln << endl;

	return 0;
}
