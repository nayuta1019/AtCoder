#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, M, X, A[110], masu[110] = {0}, f=0, b=0;

  cin >> N >> M >> X;
  for(int i = 0; i < M; i++) cin >> A[i];
  for(int i = 0; i < M; i++) masu[A[i]] = 1;

  for(int i = 0; i < X; i++) f += masu[i];
  for(int i = X; i <= N; i++) b += masu[i];

  if(f < b) cout << f << endl;
  else cout << b << endl;

	return 0;
}
