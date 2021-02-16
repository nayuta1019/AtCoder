/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    double A, B, C, D;

    cin >> A >> B >> C >> D;

    if(B/A < D/C) cout << "AOKI" << endl;
    else if(D/C < B/A)cout << "TAKAHASHI" << endl;
    else cout << "DRAW" << endl;

    return 0;
}
