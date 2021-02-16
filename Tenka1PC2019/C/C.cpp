/**
Tenka1PBC
2019/04/20/ 自力AC
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

    int N;
    string s;
    cin >> N >> s;

    int ans = INF;
    vector<int> b(N+1, 0), w(N+1, 0);
    rep(i, N){
        if(0 <= i-1){
            if(s[i] == '#'){
                b[i] += b[i-1] + 1;
                w[i] = w[i-1];
            }else{
                b[i] = b[i-1];
                w[i] += w[i-1] + 1;
            }
        }else{
            if(s[i] == '#'){
                b[i] += 1;
                w[i] = 0;
            }else{
                w[i] += 1;
                b[i] = 0;
            }
        }
    }


    rep(i, N){
        int sum = 0;
        sum = (w[N-1] - w[N-i]) + b[N-i];

        ans = min(ans, sum);
    }
    if(N == 1) ans = 0;
    if(N == 2){
        if(s[0] == '.' && s[1] == '#') ans = 0;
    }
    cout << ans << endl;

    return 0;
}