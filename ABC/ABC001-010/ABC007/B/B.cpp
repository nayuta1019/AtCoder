/**
2018/10/26/ 初見AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>
#include <queue>

using namespace std;

int main(){
    string a;

    cin >> a;

    bool flag = true;
    string ans;
    if(a.size() != 1) ans = a.substr(0, a.size()-1);
    else if(a != "a") ans = a[0] - 1;
    else flag = false;

    if(flag) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}