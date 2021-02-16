/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;

    int res = a % b;
    if(res == 0) cout << res << endl;
    else{
        res = b - res;
        cout << res << endl;
    }

    return 0;
}
