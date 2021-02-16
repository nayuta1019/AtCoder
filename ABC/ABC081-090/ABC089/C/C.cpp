/**
20181016未完成

 **/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;

long long Factorial(long long k){
    long long ans = 1;
    for(long long i = 1; i <= k; i++) ans *= i;

    return ans;
}

long long nPk(long long n, long long k){
    long long ans = 1;
    for(long long i = n-k+1; i <= n; i++) ans *= i;
    
    return ans;
}

long long nCk(long long n, long long k){
    
    return nPk(n, k) / Factorial(k); 
}
 
int main(){
    long long int N;
    string S[100001];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> S[i];

    long long int cnt[5] = {0};
    for(int i = 0; i < N; i++){
        if(S[i][0] == 'M') cnt[0]++;
        else if(S[i][0] == 'A') cnt[1]++;
        else if(S[i][0] == 'R') cnt[2]++;
        else if(S[i][0] == 'C') cnt[3]++;
        else if(S[i][0] == 'H') cnt[4]++;
    }

    long long int ans = 1, c = 0;
    for(int i = 0; i < 5; i++){
        if(cnt[i] != 0) ans *= cnt[i];
        else c++;
    }

    if(2 < c)cout << "0" << endl;
    else{
        long long int n;
        n = 5 - c;
        if(n < 4){
            cout << ans << endl;
        }else{
            ans *= nCk(n, 3);
            for(int i = 0; i < 5; i++){
                if(cnt[i] != 0) ans -= (cnt[i] - 1);
            }
            cout << ans << endl;
        }
    }

    return 0;
}