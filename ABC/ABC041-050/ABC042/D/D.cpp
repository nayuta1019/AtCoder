/**
ABC042
2019/04/25/ 解説AC
ACできるが手元の環境で動かない
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

ll arr[1100000];
ll kaijou(ll x){
    if(x == 0) return 1;
    if(x == 1) return 1;
    if(arr[x] != 0) return arr[x];
    arr[x] = x*kaijou(x-1) % MOD;
    return arr[x];
}

long long calcComb(int a, int b){
    if(b > a - b) return calcComb(a, a - b);

    long long ansMul = 1;
    long long ansDiv = 1;
    /*
    for(int i = 0; i < b; i++){
        ansMul *= (a - i);
        ansDiv *= (i + 1);
        ansMul %= MOD;
        ansDiv %= MOD;
    }
    */

    //long long ans = ansMul * modpow(ansDiv, MOD - 2) % MOD;
    //cout << a-b << endl;
    long long ans = kaijou(a) * modpow(kaijou(a-b), MOD-2);
    ans %= MOD;
    ans *= modpow(kaijou(b), MOD - 2 );
    ans %= MOD;
    //cout << ans << endl;
    return ans;
}

ll c1[110000], c2[110000];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    ll h, w, a, b; cin >> h >> w >> a >> b;



    ll ans = 0;
    FOR(i, b, w){
        c1[i] = calcComb(h-a-1+i, i);
        c2[i] = calcComb(a-1+w-i-1, w-i-1);
    }

    
    rep(i, w-b){
        ans += c1[b+i]*c2[b+i];
        ans %= MOD;
    }
    

    cout << ans << endl;

    return 0;
}
