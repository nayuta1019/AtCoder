/**
2018/10/22/
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


const int nmax = 67;

int main(){
    
    int N, M, P[nmax][nmax];

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        P[x-1][y-1] = 1;
    }

    int ans = 1;
    for(int i = 1; i < (1<<N); i++){
        int t = bitset<32>(i).count();
        bool flag = true;

        if(ans > t)continue;

        for(int j = 0; j < N; j++){
            for(int k = j + 1; k < N; k++){
                if(P[j][k] != 1 && i>>j & i>>k &1) flag = false;
            }
        }
        if(flag) ans = t;
    }

    cout << ans << endl;

    return 0;
}