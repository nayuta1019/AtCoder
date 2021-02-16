/**
2019/05/12/ 解説AC
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

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int j = 0;
    vector<int> v;
    for(int i = 1; i <= N; i++){
        if(i == N || a[i] != a[i-1]){
            v.push_back(i-j);
            j = i;
        }
    }

    //退屈さを二分探索
    //退屈さをX以下にする
    int xl = 1, xr = N;
    while(xl != xr){
        int x = (xl + xr) / 2;
        int cnt = 0;
        for(auto L : v) cnt += L / (x+1);
        if(cnt <= K) xr = x;
        else xl = x+1;
    }

    cout << xl << endl;

    return 0;
}