/**
2018/10/23/ 初見AC
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

    double ans = 0;
    for(int i = 1; i <= N; i++) ans += (double)10000 * i / N;
    
    cout << ans << endl;

    return 0;
}