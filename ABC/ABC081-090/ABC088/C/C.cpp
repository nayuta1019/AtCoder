/**
2018/10/16 自力AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;

typedef long long ll;

int main(){
    int c[110][110];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        while( (c[i][0] != 0 && c[i][1] != 0) && c[i][2] != 0){
            c[i][0]--;
            c[i][1]--;
            c[i][2]--;
        }
    }

    bool flag = true;
    if( c[0][0] != c[1][0] || c[0][0] != c[2][0] ) flag = false;
    if( c[0][1] != c[1][1] || c[0][1] != c[2][1] ) flag = false;
    if( c[0][2] != c[1][2] || c[0][2] != c[2][2] ) flag = false;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}