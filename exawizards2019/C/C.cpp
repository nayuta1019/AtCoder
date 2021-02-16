/**
エクサウィザーズ2019
2019/03/30/ 未完成
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

    int N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<int> masu(N+1, 1);
    vector< vector<int> >al(27, vector<int>() );

    rep(i, N){
        al[s[i]-'A'].push_back(i);
    }

    rep(_, Q){
        char t, d;
        cin >> t >> d;
        rep(i, al[t-'A'].size()){
            int index = al[t-'A'][i];
            if(d == 'R'){
                if(index < N-1) masu[index+1] += masu[index];
                masu[index] = 0;
            }else{
                if(0 < index) masu[index-1] += masu[index];
                masu[index] = 0;
            }
            
        }
    }

    int ans = 0;
    rep(i, N) ans += masu[i];

    cout << ans << endl;

    return 0;
}