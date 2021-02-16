#include <iostream>
using namespace std;

#define N_MAX 101

int main(){

  int N, A[N_MAX], s, smax;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  smax = 0;
  for(int i = 0; i < N-1; i++){
    for(int j = i+1; j < N; j++){
      s = A[i] - A[j];
      if(s < 0) s *= -1;
      if(smax < s) smax = s;
    }
  }

  cout << smax << endl;

  return 0;
}
