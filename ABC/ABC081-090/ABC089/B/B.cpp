#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N;
  char S[110];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> S[i];

  sort(S, S+N);

  if(S[N-1] == 'Y') cout << "Four" << endl;
  else cout << "Three" << endl;

	return 0;
}
