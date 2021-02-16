/**
2018/10/23/ 自力AC
ダメだった時点でbreakする
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

char str[7] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

int main(){
    string S, T;

    cin >> S >> T;

    bool flag = true;
    for(int i = 0; i < S.size(); i++){

        if(S[i] == T[i]) continue;
        else flag = false;

        if(S[i] == '@'){
            for(int j = 0; j < 7; j++){
                if(str[j] == T[i]) flag = true;
            }
        }

        if(T[i] == '@'){
            for(int j = 0; j < 7; j++){
                if(str[j] == S[i]) flag = true;
            }
        }

        if(!flag) break;
        
    }

    if(flag) cout << "You can win" << endl;
    else cout << "You will lose" << endl;

    return 0;
}