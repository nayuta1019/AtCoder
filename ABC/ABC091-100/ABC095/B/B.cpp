#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, X, m[110];

  cin >> N >> X;
  for(int i = 0; i < N; i++) cin >> m[i];

  sort(m, m+N);

  int a = X, ans = N;
  for(int i = 0; i < N; i++) a -= m[i];

  if(a != 0) ans += a / m[0];

  cout << ans << endl;
  
	return 0;
}
