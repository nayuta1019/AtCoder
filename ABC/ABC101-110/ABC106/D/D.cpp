// 未完成
#include <iostream>
#include <string>

using namespace std;

int main(){

  int N, M, Q, ans;
  int L[200001], R[200001], p[100001], q[100001];
  cin >> N >> M >> Q;

  for(int i = 0; i < M; i++){
    cin >> L[i] >> R[i];
  }
  for(int i = 0; i < Q; i++){
    cin >> p[i] >> q[i];
  }

  for(int i = 0; i < Q; i++){
    ans = 0;

    for(int j = 0; j < M; j++){
      if(p[i] <= L[j] && R[j] <= q[i]) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
