#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int N, now = 0, count = 0;
  vector<int> a;

  cin >> N;
  for(int i = 0; i < N; i++){
    int x;
    cin >> x;
    x--;
    a.push_back(x);
  }

  while(1){
    if(now == 1){
      cout << count << endl;
      break;
    }
    if(N <= count){
      cout << "-1" << endl;
      break;
    }
    count++;
    now = a[now];
  }

	return 0;
}
