#include <iostream>
#include <string>

using namespace std;

int main(){

  int N, c = 0, ans = 0;

  cin >> N;

  for(int j = 1; j <= N; j+=2){
    c = 0;
    for(int i = 1; i <= j; i++){
      if(j % i == 0) c++;
    }
    if(c == 8) ans++;

  }
  cout << ans << endl;

  return 0;
}
