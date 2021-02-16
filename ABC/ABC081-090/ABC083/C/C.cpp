/**
2018/10/28/ 初見AC
**/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){

    long long X, Y;
    cin >> X >> Y;

    long long ans = 0, num = X;

    while(num <= Y){
        ans++;
        num *= 2;
    }

    cout << ans << endl;

    return 0;
}