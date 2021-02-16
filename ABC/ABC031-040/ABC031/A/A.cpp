/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int A, D;
    cin >> A >> D;

    if( A*(D+1) <= (A+1)*D ) cout << (A+1)*D << endl;
    else cout <<  A*(D+1) << endl;

    return 0;
}
