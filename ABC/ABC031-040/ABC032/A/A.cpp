/**
2018/11/04/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int a, b, n;
    cin >> a >> b >> n;

    while(true){
        if(n%a == 0 && n%b == 0) break;
        n++;
    }

    cout << n << endl;

    return 0;
}
