/**
ABC110
2019/02/15/ 解説AC
author:chokudai
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

long long modpow(long long a, int p){
    if(p == 0) return 1;
    if(p % 2 == 0){
        int halfP = p / 2;
        long long half = modpow(a, halfP);
        return half * half % MOD;
    }else{
        return a * modpow(a, p-1) % MOD;
    }
}

long long calcComb(int a, int b){
    if(b > a - b) return calcComb(a, a - b);

    long long ansMul = 1;
    long long ansDiv = 1;
    for(int i = 0; i < b; i++){
        ansMul *= (a - i);
        ansDiv *= (i + 1);
        ansMul %= MOD;
        ansDiv %= MOD;
    }

    long long ans = ansMul * modpow(ansDiv, MOD - 2) % MOD;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N, M;
    cin >> N >> M;

    int Mnokori = M;
    long long ans = 1;
    for(int i = 2; i * i <= Mnokori; i++){
        if(Mnokori % i == 0){
            int cnt = 0;
            while(Mnokori % i == 0){
                cnt++;
                Mnokori /= i;
            }
            ans *= calcComb(N + cnt - 1, N - 1);
            ans %= MOD;
        }
    }
    if(Mnokori != 1){
        ans *= calcComb(N + 1 - 1, N - 1);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}