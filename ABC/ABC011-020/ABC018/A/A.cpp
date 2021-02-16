/**
2018/11/03/ 初見AC  ちょい苦戦
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int p[3], r[3];

    for(int i = 0; i < 3; i++){
        cin >> p[i];
        r[i] = p[i];
    }
    

    sort(r, r+3, greater<int>());
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(p[i] == r[j]) cout << j+1 << endl;
        }
    }


    return 0;
}
