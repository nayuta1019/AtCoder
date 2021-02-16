#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, D, X, A[110], ans=0;

  cin >> N >> D >> X;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++){
    int day = 1;
    while(day <= D){
      ans++;
      day += A[i];
    }
  }
  ans += X;

  cout << ans << endl;

	return 0;
}
