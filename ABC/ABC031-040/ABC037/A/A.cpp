/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    if(A < B) cout << C / A << endl;
    else cout << C / B << endl;

    return 0;
}
