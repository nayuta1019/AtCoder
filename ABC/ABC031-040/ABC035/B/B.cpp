/**
ABC035
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
    string s;
    int t;
    cin >> s >> t;
    int x = 0, y = 0, cnt = 0;
    rep(i, s.size()){
        if(s[i] == 'L') x--;
        else if(s[i] == 'R') x++;
        else if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        else if(s[i] == '?') cnt++;
    }

    int ans  = abs(x) + abs(y);
    if(t == 1){
        ans += cnt;
    }else if(t == 2){
        if(0 <= ans - cnt) ans -= cnt;
        else{
            cnt -= ans;
            if(cnt % 2 == 1) ans = 1;
            else ans = 0;
        }
    }

    cout << ans << endl;

    return 0;
}