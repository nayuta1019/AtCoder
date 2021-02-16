/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int A;
    cin >> A;

    int ans = 0;
    for(int x = 1; x < A; x++){
        int y = A - x;
        if(ans < x*y) ans = x*y;

    }

    cout << ans << endl;

    return 0;
}
