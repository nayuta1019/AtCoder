/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int A, B, C, K, S, T;
    cin >> A >> B >> C >> K >> S >> T;

    int res = 0;
    if(K <= S+T) res = (A-C)*S + (B-C)*T;
    else res = A*S + B*T;

    cout << res << endl;

    return 0;
}
