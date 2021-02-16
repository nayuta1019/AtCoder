/**
ARC005
2018/12/31/ 自力AC
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
    const string str1 = "TAKAHASHIKUN";
    const string str2 = "Takahashikun";
    const string str3 = "takahashikun";
    int n, ans = 0;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        if(i == n-1) s.pop_back();
        if(s == str1) ans++;
        else if(s == str2) ans++;
        else if(s == str3) ans++;
    }

    cout << ans << endl;

    return 0;
}