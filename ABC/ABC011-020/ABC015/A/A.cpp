/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string A, B;

    cin >> A >> B;

    if(A.size() < B.size()) cout << B << endl;
    else cout << A << endl;

    return 0;
}
