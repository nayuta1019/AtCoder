/**
ABC034
2018/12/18/ 解説AC
フェルマーの小定理
modpow
**/
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

ll modpow(int x, int p){
    if(p == 0) return 1;
    else{
        if(p % 2 == 1) return x * modpow(x, p-1) % MOD;
        else{
            ll res = modpow(x, p/2);
            return res * res % MOD;
        }
    }
}

ll comb(ll n, int r){
    ll mul = 1;
    ll div1, div2;
    for(int i = 1; i <= n; i++){
        mul *= i;
        mul %= MOD;
        if(r == i) div1 = modpow(mul, MOD-2);
        if(n-r == i) div2 = modpow(mul, MOD-2);
    }
    return mul * div1 % MOD * div2 % MOD;

}

int main(){
    int w, h;
    cin >> w >> h;

    cout << comb(w+h-2, h-1) << endl;

    return 0;
}