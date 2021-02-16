/**
ABC044
2019/01/17/ 解説AC
**/
#include<iostream>

using namespace std;

long long dp[55][5555];
int n, a, x[55];

main(){
    cin >> n >> a;
    for(int i = 0; i < n; i++) cin >> x[i];
    dp[0][2500] = 1;
    for(int i = 0; i < n; i++){
        x[i] -= a;

        for(int j = 0; j <= 5000; j++){
            dp[i+1][j] += dp[i][j];
            if(j <= 5000-x[i]) dp[i+1][j+x[i]] += dp[i][j];
        }
    }
    cout << dp[n][2500]-1 << endl;

    return 0;
}