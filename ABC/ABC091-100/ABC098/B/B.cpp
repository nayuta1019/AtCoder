#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int N;
  string S;

  cin >> N >> S;

  int ans = 0;
  for(int i = 1; i < N; i++){
    int count = 0;

    for(char c ='a'; c <= 'z'; c++){
      bool left = false, right = false;

      for(int j = 0; j < i; j++)
        if(S[j] == c)
          left = true;

      for(int j = i; j < N; j++)
        if(S[j] == c)
          right = true;

      if(left && right)
      count++;
    }

    if(ans < count) ans = count;
  }

  cout << ans << endl;

	return 0;
}
