/**
2018/10/21/ 初見AC
C++の復習
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
    int m, vv;

    cin >> m;

    if(m < 100) vv = 0;
    else if(m <= 5000) vv = m / 100;
    else if(m <= 30000) vv = m / 1000 + 50;
    else if(m <= 70000) vv = (m / 1000 - 30 ) / 5 + 80;
    else vv = 89;

    cout.width(2);
    cout.fill('0');
    cout << vv << endl;
 
    return 0;
}