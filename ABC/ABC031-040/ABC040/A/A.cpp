/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;

    if(x-1 < n-x) cout << x-1 << endl;
    else cout << n-x << endl;

    return 0;
}
