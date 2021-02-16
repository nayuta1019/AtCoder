/**
ABC122
2019/03/28/ 解説用
**/
#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
int dp[101][4][4][4];

int main(){
    int N;
    cin >> N;

    dp[0][3][3][3] = 1;

    for(int len = 0; len < N; len++){
        for(int c1 = 0; c1 < 4; c1++){
            for(int c2 = 0; c2 < 4; c2++){
                for(int c3 = 0; c3 < 4; c3++){
                    if(dp[len][c1][c2][c3] == 0) continue;

                    for(int a = 0; a < 4; a++){
                        if(a == 2 && c1 == 1 && c2 == 0) continue;
                        if(a == 2 && c1 == 0 && c2 == 1) continue;
                        if(a == 1 && c1 == 2 && c2 == 0) continue;
                        if(a == 2 && c1 == 1 && c3 == 0) continue;
                        if(a == 2 && c2 == 1 && c3 == 0) continue;

                        dp[len + 1][a][c1][c2] += dp[len][c1][c2][c3];
                        dp[len + 1][a][c1][c2] %= mod;
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int c1 = 0; c1 < 4; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            for(int c3 = 0; c3 < 4; c3++){
                ans += dp[N][c1][c2][c3];
                ans %= mod;
            }
        }
    }

    cout << ans << endl;

    return 0;
}