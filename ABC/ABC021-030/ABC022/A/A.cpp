/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int N, S, T;
    cin >> N >> S >> T;

    int W, ans=0;
    cin >> W;
    if(S <= W && W <= T) ans++;
    for(int i = 0; i < N-1; i++){
        int A;
        cin >> A;
        W += A;

        if(S <= W && W <= T) ans++;
    }

    cout << ans << endl;

    return 0;
}
