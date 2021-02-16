#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int N, M, a[51], b[51], c[51], d[51], mn, mn_max, ans[51];

  cin >> N >> M;

  for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
  for(int i = 0; i < M; i++) cin >> c[i] >> d[i];

  for(int i = 0; i < N; i++){
    mn_max = INT_MAX;
    for(int j = 0; j < M; j++){
      mn = abs(a[i] - c[j]) + abs(b[i] - d[j]);

      if(mn < mn_max){
        mn_max = mn;
        ans[i] = j+1;
      }
    }
  }

  for(int i = 0; i < N; i++) cout << ans[i] << endl;

  return 0;
}
