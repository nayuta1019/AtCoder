#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, a[110], A=0, B=0;

  cin >> N;
  for(int i = 0; i < N; i++) cin >> a[i];

  sort(a, a+N);
  reverse(a, a+N);

  for(int i = 0; i < N; i++){
    if(i%2==0) A += a[i];
    else B += a[i];
  }

  int ans = A - B;

  cout << ans << endl;

	return 0;
}
