/**
2018/12/13/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
int C[110];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> C[i];

    double ans = 0;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(i != j && C[i] % C[j] == 0) cnt++;   //約数の数
        }
        if(cnt % 2 == 1){
            ans += (double) 1.0 / 2.0;
        }else{
            ans += (double) (cnt + 2) / (2 * cnt + 2);
        }
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
