/**
ABC123
2019/04/06/ 自力AC
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

    ll N, x[6];
    cin >> N;
    rep(i, 5) cin >> x[i];

    ll y = 1e16;
    rep(i, 5) y = min(y, (ll)x[i]);

    if(y < N){
        long double p = (long double)(N-y)/y;

        ll q = (long double)p+(long double)0.9;

        cout << (ll)5 + q << endl;
    }else{
        cout << 5 << endl;
    }



    return 0;
}