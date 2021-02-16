/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int A, B;
    cin >> A >> B;

    int ans = 1, total = A;
    while(total < B){
        ans++;
        total += A;
    }

    cout << ans << endl;

    return 0;
}
