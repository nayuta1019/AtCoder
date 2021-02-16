#include <iostream>
using namespace std;

int main(){
  int T;
  long A[301], B[301], C[301], D[301], ans = 0;


  cin >> T;
  for(int i = 0; i < T; i++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];

    ans = A[i] - B[i];

    if(ans < 0){
        cout << "No" << endl;
        continue;
    }

    if(C[i] < ans){
        ans = A[i] % B[i];
        if(C[i] < ans){
            cout << "No" << endl;
            continue;
        }else{
            cout << "Yes" << endl;
            continue;
        }
    }

    if(B[i] == D[i]){
        if(ans > C[i]){
            cout << "No" << endl;
            continue;
        }else{
            cout << "Yes" << endl;
            continue;
        }
    }

    while(0 < ans && ans <= C[i]){
        ans += -B[i] + D[i];
    }

    if(ans < 0){
        cout << "No" << endl;
        continue;
    }

    if(B[i] <= ans) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
