#include <iostream>
using namespace std;

int main(){
  int N, ans = 0;
  int a[100];


  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  for(int i = 1; i < N; i += 2){
    if(a[i-1] != a[i] && a[i] == a[i+1]){
      i--;
      continue;
    }else if(a[i-1] != a[i] && a[i] != a[i+1]){
      continue;
    }else{
      ans++;
    }
  }

  cout << ans << endl;

  return 0;

}
