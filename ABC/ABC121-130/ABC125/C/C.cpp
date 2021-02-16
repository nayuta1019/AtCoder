/**
ABC125
2019/04/27/ 未完成
2019/05/01/ 解説AC
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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


// 最大公約数
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}



int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    vector<int> left(n+1, 0), right(n+1, 0);
    for(int i = 0; i < n; i++) left[i+1] = gcd(left[i], a[i]);
    for(int i = n-1; 0 <= i; i--) right[i] = gcd(right[i+1], a[i]);

    int res = 0;
    for(int i = 0; i < n; i++){
        int l = left[i];
        int r = right[i+1];
        chmax(res, gcd(l, r));
    }

    cout << res << endl;

    return 0;
}