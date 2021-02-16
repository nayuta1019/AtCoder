/**
2018/10/21/ 初見AC
小数点しっかり！
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <cfenv>
#include <cmath>

using namespace std;

double Rounding(double x){
    int a = x * 10 + 0.5;
    double b = (double)a / 10;
    return b;
}

int main(){
    double Deg, Dis;
    string Dir;
    int W;

    string direction[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
                            "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

    cin >> Deg >> Dis;

    Deg = Deg / 10 + 360.0 / 16.0 / 2.0;
    if(360 <= Deg) Deg -= 360.0;
    int cnt = 0;
    //cout << "Deg = " << Deg << endl;
    for(double i = 360.0 / 16.0; i <= 360.0; i+=360.0/16.0){
        //cout << "i = " << i << endl;
        //cout << "cnt = " << cnt << endl;
        if(Deg < i){
            Dir = direction[cnt];
            //cout << Dir << endl;
            break;
        }
        cnt++;
    }

    Dis /= 60;
    //cout << "Dis = " << Dis << endl;
    Dis = Rounding(Dis);
    //cout << "Dis = " << Dis << endl;
    if(Dis <= 0.2) W = 0;
    else if(Dis <= 1.5) W = 1;
    else if(Dis <= 3.3) W = 2;
    else if(Dis <= 5.4) W = 3;
    else if(Dis <= 7.9) W = 4;
    else if(Dis <= 10.7) W = 5;
    else if(Dis <= 13.8) W = 6;
    else if(Dis <= 17.1) W = 7;
    else if(Dis <= 20.7) W = 8;
    else if(Dis <= 24.4) W = 9;
    else if(Dis <= 28.4) W = 10;
    else if(Dis <= 32.6) W = 11;
    else  W = 12;

    if(W == 0) Dir = "C";

    cout << Dir << " " << W << endl;


    return 0;
}