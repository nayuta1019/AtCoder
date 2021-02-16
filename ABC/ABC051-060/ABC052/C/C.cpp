/**
ABC052
2019/01/11/ 解説AC
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

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;

    vector<bool> prime(N+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= N; i++){
        if(prime[i] == false) continue;
        int tmp = 2;
        while(tmp*i <= N){
            prime[tmp*i] = false;
            tmp++;
        }
    }

    ll ans = 1;
    rep(i, N+1){
        if(prime[i] == false) continue;
        ll cnt = 0;

        FOR(j, i, N+1){
            int tmp = j;
            while(tmp % i == 0 && tmp != 0){
                tmp /= i;
                cnt++;
            }
        }
        if(0 < cnt) ans *= (cnt+1);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}