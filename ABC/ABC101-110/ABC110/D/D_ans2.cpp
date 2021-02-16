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

const int mod = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

long long modpow(long long m, int n) {
    if (n == 0) return 1;
    long long ret = modpow(m * m % mod, n / 2);
    if (n % 2) ret *= m;
    return ret % mod;
}

long long calcComb(int a, int b){
	if (b > a - b) return calcComb(a, a - b);

	long long ansMul = 1;
	long long ansDiv = 1;
	for(int i = 0; i < b; i++){
		ansMul *= (a - i);
		ansDiv *= (i + 1);
		ansMul %= mod;
		ansDiv %= mod;
	}
	//ansDivの逆元
	long long ans = ansMul * modpow(ansDiv, mod - 2) % mod;
	return ans;
}

int main(){
    int N, M;
    cin >> N >> M;

    int MNokori = M;
	ll ans = 1;
	for(int i = 2; i * i <= MNokori; i++){
		if(MNokori % i == 0){
			int cnt = 0;
			while(MNokori % i == 0){
				cnt++; MNokori /= i;
			}
			//cntが2^Xとか3^XのXの部分
			ans *= calcComb(N + cnt - 1, N - 1); //N-1はcntと同じ
			ans %= mod;
		}
	}
	if(MNokori != 1){
		//最後に素数が残ってる分を処理する
		ans *= calcComb(N, N - 1); //N-1はcntと同じ
		ans %= mod;
	}

	cout << ans << endl;

    return 0;
}