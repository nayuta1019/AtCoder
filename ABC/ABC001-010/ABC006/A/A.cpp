/**
2018/10/24/ 初見AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>

using namespace std;

int main(){
    int N;

    cin >> N;

    bool flag = false;

    if(N == 3) flag = true;
    if(N % 3 == 0) flag = true;

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}