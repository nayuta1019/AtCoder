/**
2018/12/02/ 自力AC
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
    cin >> s;

    int ans = 1e9;
    for(int i = 0; i < s.size()-2; i++){
        string str = "";
        str += s[i];
        str += s[i+1];
        str += s[i+2];
        //cout << "str = " << str << endl;
        int dis = abs(753 - toInt(str));
        ans = min(ans, dis);
    }

    cout << ans << endl;

    return 0;
}