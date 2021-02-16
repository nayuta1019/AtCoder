/**
2018/10/22/ 自力AC
小数点を表示する！
cout << fixed << setprecision(1);
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include<iomanip>

using namespace std;

int main(){
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    xb -= xa;
    xc -= xa;
    yb -= ya;
    yc -= ya;

    double ans = (double)abs(xb*yc - yb*xc) / 2.0;

   
    cout << fixed << setprecision(1);
	cout << ans << endl;

    return 0;
}