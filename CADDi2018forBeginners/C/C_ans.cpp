/**
CADDi2018forBeginners
2018/12/23/ 解説AC
素因数分解
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

int main(){
    ll N, P;
    cin >> N >> P;

    ll ans = 1;

    if(N == 1){
        cout << P << endl;
        return 0;
    }

    for(ll d = 2; d*d <= P; d++){
        int cnt = 0;
        while(P%d == 0){
            P /= d;
            cnt++;
        }

        if(cnt){
            ll k = cnt / N;
            for(int i = 1; i <= k; i++){
                ans *= d;
            }
        }
    }

    cout << ans << endl;

    return 0;
}