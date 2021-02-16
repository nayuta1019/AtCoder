#include <iostream>
using namespace std;

#define N_MAX 200002

int main(){

  int N, A[N_MAX], s, stotal, smin, b, Amax, bmax;

  cin >> N;
  Amax = 0;
  for(int i = 1; i <= N; i++){
    cin >> A[i];
    if(Amax < A[i]) Amax = A[i];
  }

  if(Amax < N) bmax = N;
  else bmax = Amax;

  // smin初期値
  smin = 0;
  for(int i = 1; i <= N; i++){
    s = A[i] - (-1*bmax + i);
    if(s < 0) s *= -1;
    smin += s;
  }


  for(b = -1*bmax + 1; b <= bmax; b++){
    stotal = 0;
    for(int i = 1; i <= N; i++){
      s = A[i] - (b + i);
      if(s < 0) s *= -1;
      stotal += s;
    }
    if(stotal < smin) smin = stotal;
  }

  cout << smin << endl;

  return 0;
}
