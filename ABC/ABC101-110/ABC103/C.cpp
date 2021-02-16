#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

  int N, a[1000000], f_max = 0;

  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  for(int i = 0; i < N; i++){
    f_max += a[i] - 1;
  }

  cout << f_max << endl;

  return 0;

}
