/**
2018/11/07/ 解説AC
しゃくとり法。累積和を使ったDP
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

const int MOD = 1000000007;
int dp[110000];
int sum[110000];

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> f(N);
    for(int i = 0; i < N; i++){
        cin >> f[i];
        f[i]--;
    }


    /* しゃくとり法 */
    vector<int> fnum(M, 0); // 区間に種類 i が何個あるか
    vector<int> L(N+1, 0);  // 各 i に対するしゃくとり法の区間
    int left = 0;
    for(int right = 0; right < N; right++){
        fnum[f[right]]++;
        while( left < right && 1 < fnum[f[right]] ){
            fnum[f[left]]--;
            left++;

        }

        L[right+1] = left;
    }

    /* 累積和で高速化した DP */
    dp[0] = 1;
    sum[0] = 0;
    sum[1] = 1;
    for(int i = 1; i <= N; i++){
        dp[i] = (sum[i] - sum[L[i]] + MOD) % MOD;
        sum[i+1] = (sum[i] + dp[i]) % MOD;
    }

    cout << dp[N] << endl;

    return 0;
}