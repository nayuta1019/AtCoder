/**
ABC116
2019/01/20/ 自力AC
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
    cin >> N;
    vector<int> h(N);
    rep(i, N) cin >> h[i];
    vector<int> f(N);

    ll ans = 0;
    bool flag = true;
    while(flag){
        int left = 0;
        rep(j, N){
            if(h[j] != 0){
                left = j;
                break;
            }
            if(j == N-1) flag = false;
        }
        bool check = false;
        for(int j = left; j < N; j++){
            if(h[j] != 0){
                h[j]--;
                ans++;
                if(check == false) check = true;
                else ans--;
            }else{
                check = false;
            }
        }
    }

    cout << ans << endl;

    return 0;
}