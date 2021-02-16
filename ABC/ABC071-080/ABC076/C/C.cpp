/**
2018/10/19/ 解説AC
flagの管理をしっかりする
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
    string s, T, S;

    cin >> s >> T;

    bool flag = false;
    for(int i = 0; i < s.size()-T.size()+1; i++){

        string check = s.substr(i, T.size());
        bool f = false;

        for(int j = 0; j < check.size(); j++){
            if(check[j] != '?' && check[j] != T[j]){
                f = false;
                break;
            }else{
                f = true;
            }
        }

        if(f){
            S = s;
            int z = 0;
            for(int k = i; k < T.size()+i; k++){
                S[k] = T[z];
                z++;
            }
            flag = true;

        }

    }

    if(flag){
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '?') S[i] = 'a';
        }
        cout << S << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }

    return 0;
}