#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int i, min = 0, mid = 0, max = 0, cost = 0;
  int A[3];



  for(i = 0; i < 3; i++){
    cin >> A[i];
  }

  min = A[0];
  max = A[0];
  for(i = 1; i < 3; i++){
    if( A[i] < min) min = A[i];
    if( max < A[i]) max = A[i];
    if(min != A[i] && max != A[i]) mid = A[i];
  }


  cost = mid - min;
  cost += max - mid;

  cout << cost << endl;

  return 0;

}
