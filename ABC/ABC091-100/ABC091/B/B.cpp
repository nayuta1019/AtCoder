#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N, M, ans=0, total=1;
  string s[110] = {""}, t[110];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> s[i];

  cin >> M;
  for(int i = 0; i < M; i++) cin >> t[i];

  sort(s, s+N);
  sort(t, t+M);

  for(int i = 0; i < N; i++){

    if(s[i] == s[i+1]){
      total++;
      continue;
    }
    for(int j = 0; j < M; j++){
      if(s[i] == t[j]) total--;
    }
    if(ans < total) ans = total;
    total = 1;
  }
  cout << ans << endl;

	return 0;
}
