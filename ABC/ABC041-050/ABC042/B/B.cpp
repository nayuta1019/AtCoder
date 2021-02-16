#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

  int N, L;
  string str[110];

  cin >> N >> L;
  for(int i = 0; i < N; i++){
    cin >> str[i];
  }

  sort(str, str+N);

  for(int i = 0; i < N; i++){
    cout << str[i];
  }

  cout << endl;

  return 0;

}
