/**
ABC045
2019/04/25/ 解説AC
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

    ll h, w, n; cin >> h >> w >> n;
    vector< vector<ll> > dots;

    rep(i, n){
        ll a, b; cin >> a >> b;
        rep(j, 3){
            rep(k, 3){
                if(1 < a+j-1 && a+j-1 <= h-1 && 1 < b+k-1 && b+k-1 <= w-1){
                    vector<ll> dot{a+j-1, b+k-1};
                    dots.push_back(dot);
                }
            }
        }
    }
    sort(all(dots));
    vector<ll> ans(10, 0);
    if( (int)dots.size() != 0 ){
        int count = 1;
        FOR(i, 1, (int)dots.size()){
            if(dots[i-1] == dots[i]){
                count++;
            }else{
                ans[count]++;
                count = 1;
            }
        }
        ans[count]++;
    }

    cout << (h-2)*(w-2)-accumulate(ans.begin()+1, ans.end(), 0) << endl;
    FOR(i, 1, (int)ans.size()){
        cout << ans[i] << endl;
    }

    return 0;
}