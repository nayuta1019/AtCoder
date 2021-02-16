/**
ABC050
2019/01/09/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

const int MOD = 1e9+7;
int memo[100005];

int main(){
    int N;
    cin >> N;
    bool flag = true;
    rep(i, N){
        int A;
        cin >> A;
        if(N % 2 == 0){
            if(A % 2 == 1){
                memo[A]++;
            }else{
                flag = false;
            }
        }else{
            if(A % 2 == 0){
                memo[A]++;
            }else{
                flag = false;
            }
        }
    }

    if(!flag){
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 1;
    if(N % 2 == 1){
        if(memo[0] != 1) flag = false;
        for(int i = 2; i < N; i+=2){
            if(memo[i] == 0) flag = false;
            ans = (ans * memo[i]) % MOD;
        }
    }else{
        for(int i = 1; i < N; i+=2){
            if(memo[i] == 0) flag = false;
            ans = (ans * memo[i]) % MOD;
        }
    }

    if(flag){
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}