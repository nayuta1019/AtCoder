/**
AGC017
2019/03/14/ 解説AC
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

const int CMAX = 1010;
int noinit = 1;
ll memo[CMAX][CMAX];

ll aCb(ll a, ll b){
    if(noinit){
        for(int i = 0; i < CMAX; i++){
            for(int j = 0; j < CMAX; j++){
                memo[i][j] = -1;
            }
        }
        noinit = 0;
    }

    if(b == 0 || a == b) return 1;
    if(0 <= memo[a][b]) return memo[a][b];
    return memo[a][b] = aCb(a-1, b-1) + aCb(a-1, b);
}

int N, P, A[101];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> N >> P;
    for(int i = 0; i < N; i++) cin >> A[i];

    int odd = 0, even = 0;
    for(int i = 0; i < N; i++){
        if(A[i] % 2 == 1) odd++;
        else even++;
    }

    ll ans = 0;
    int c = P;
    //P = 0 の時 2^even * (C(odd,0) + C(odd,2) + C(odd,4) + ...)
    //P = 1 の時 2^even * (C(odd,1) + C(odd,3) + C(odd,5) + ...)
    while(c <= odd) ans += aCb(odd, c), c += 2;
    for(int i = 0; i < even; i++) ans *= 2;

    printf("%lld\n", ans);

    return 0;
}