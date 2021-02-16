#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int N, M, a[51], b[51], ans[51] = {0};

  cin >> N >> M;
  for(int i = 0; i < M; i++) cin >> a[i] >> b[i];

  for(int i = 0; i < M; i++){
    ans[a[i]]++;
    ans[b[i]]++;
  }

  for (int i = 1; i <= N; i++) cout << ans[i] << endl;

	return 0;
}
