/**
2018/11/15/ 解説用
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

const int mod = 1e9+7;

int main(){
    ll ans = 1;
    int N;
    cin >> N;

    bool prime[N+1];
    fill(prime,prime+N+1,true);
    prime[0] = false;
    prime[1] = false;
    //エラトステネスの篩
    for(int i = 2; i * i <= N; i++){
        if(prime[i] == false) continue;
        else{
            int x = 2;
            while(x*i <= N){
                prime[x*i] = false;
                x++;
            }
        }
    }

    rep(i,N+1){
        if(prime[i] == false) continue;
        else{
            ll cnt = 0;
            FOR(j,i,N+1){
                int tmp = j;
                while(tmp % i == 0 && tmp != 0){
                    tmp /= i;
                    cnt++;
                }
            }
            if(cnt > 0) ans *= (cnt+1);
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}