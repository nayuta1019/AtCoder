/**
2018/10/27/ 初見AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>
#include <queue>

using namespace std;

int main(){
    string S;
    cin >> S;

    int ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '1') ans++;
    }

    cout << ans << endl;

    return 0;
}