/**
ABC114
2018/12/11/ 解説AC
再帰関数
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

ll N, ans = 0;

void dfs(ll x, ll a, ll b, ll c){
    if(N < x) return ;
    if(a && b && c) ans++;
    dfs(x*10+3, 1, b, c);
    dfs(x*10+5, a, 1, c);
    dfs(x*10+7, a, b, 1);
}

int main(){

    cin >> N;

    dfs(0, 0, 0, 0);

    cout << ans << endl;

    return 0;
}