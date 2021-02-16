/**
ARC013
2019/02/12/ 解説AC
next_permutation(all(pqr));
順列の生成
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

    vector<int> nml(3), pqr(3);
    rep(i, 3) cin >> nml[i];
    rep(i, 3) cin >> pqr[i];
    
    int ans = 0;
    rep(i, 6){
        ans = max(ans, (nml[0]/pqr[0])*(nml[1]/pqr[1])*(nml[2]/pqr[2]) );
        next_permutation(all(pqr));
    }

    cout << ans << endl;

    return 0;
}