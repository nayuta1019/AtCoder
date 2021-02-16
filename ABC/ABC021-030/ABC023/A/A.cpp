/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int X;
    cin >> X;

    int sum=0;
    while(0 < X){
        sum += X%10;
        X /= 10;

    }

    cout << sum << endl;

    return 0;
}
