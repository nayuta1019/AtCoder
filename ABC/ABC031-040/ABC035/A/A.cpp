/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int W, H;
    cin >> W >> H;

    if(W%16 == 0 && H%9 == 0) cout << "16:9" << endl;
    else cout << "4:3" << endl;

    return 0;
}
