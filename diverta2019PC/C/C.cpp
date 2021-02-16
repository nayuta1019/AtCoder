/**
diverta2019
2019/05/11/ 自力AC
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

    int n;
    string s[11000];
    cin >> n;
    rep(i, n) cin >> s[i];
    
    ll a = 0, b = 0, ab = 0, br = 0;
    rep(i, n){
        rep(j, s[i].size()-1){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') ab++;
        }
        if(s[i][0] == 'B') b++;
        if(s[i][s[i].size()-1] == 'A') a++;
        if(s[i][s[i].size()-1] != 'A' && s[i][0] != 'B') br++;
    }
    if(a == n-br) a--;
    if(b == n-br) b--;
    cout << max(0LL, min(a, b)) + ab << endl;

    return 0;
}