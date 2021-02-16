#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int A, B, K;
  vector<int> ans;

  cin >> A >> B >> K;

  if(B-A+2 <= K){
    for(int i = A; i <= B; i++) cout << i << endl;
  }else{
    for(int i = A; i < A+K; i++) ans.push_back(i);
    for(int i = B; B-K < i; i--) ans.push_back(i);

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
      if(ans[i] == ans[i+1]) continue;
      cout << ans[i] << endl;
    }
  }

	return 0;
}

/**
for (int i = a ; i <= min ( b , a + k − 1 ) ; i++) printf(”%d\n ” , i );
for (int i = max( b − k + 1 , a + k ) ; i <= b ; i++) printf(”%d\n ” , i );
**/
