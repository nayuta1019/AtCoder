/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    int S = 0;
    S = (A*B)*2 + (B*C)*2 + (A*C)*2;

    cout << S << endl;

    return 0;
}
