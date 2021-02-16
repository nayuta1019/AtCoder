#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N, T[110], M, P[110], X[110], time;

  cin >> N;
  for(int i = 0; i < N; i++) cin >> T[i];
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> P[i] >> X[i];
  }

  for(int i = 0; i < M; i++){
    time = 0;
    for(int j = 0; j < N; j++){
        if(j == P[i]-1) time += X[i];
        else time += T[j];
    }
    cout << time << endl;
  }

  return 0;
}
