/**
2018/10/22/ 初見AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

char P[5] = {'a', 'i', 'u', 'e', 'o'};

int main(){
    string W;

    cin >> W;

    for(int i = 0; i < W.size(); i++){
        
        bool flag = true;
        for(int j = 0; j < 5; j++){
            if(P[j] == W[i]) flag = false;
        }
        if(flag) cout << W[i];
    }
    cout << endl;

    return 0;
}