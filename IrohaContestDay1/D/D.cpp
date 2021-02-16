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

    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(all(a), greater<int>());

    rep(i, n){
        if(i%2){
            y += a[i];
        }else{
            x += a[i];
        }
    }

    if(y < x){
        cout << "Takahashi" << endl;
    }else if(x < y){
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }

    return 0;
}