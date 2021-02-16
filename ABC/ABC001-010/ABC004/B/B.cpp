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
#include<iomanip>

using namespace std;


int main(){
    char c[4][4], ans[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ans[i][j] = c[3-i][3-j];
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << ans[i][j];
            if(j != 3) cout << " ";
        }
        cout << endl;
    }

    return 0;
}