/**
2018/11/07/ 解説用101点解法

**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

const ll MOD = 1000000007;

ll modpow(int x, int p){
	if(p == 0) return 1;
	if(p % 2) return x * modpow(x, p-1) % MOD;
	else{
	    ll res = modpow(x, p/2);
		return res*res % MOD;
	}
}

ll comb(ll n, int r){
	ll mul = 1;
	ll div1, div2;
	for(int i = 1; i <= n; i++){
		mul *= i;
		mul %= MOD;
		if(i == r) div1 = modpow(mul, MOD-2);
		if(i == n-r) div2 = modpow(mul, MOD-2);
	}
	return mul * div1 % MOD * div2 % MOD;
}

int main(){
	int w, h;
	cin >> w >> h;

	cout << comb((ll)w+h-2, w-1) << endl;

	return 0;
}