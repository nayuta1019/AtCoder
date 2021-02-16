/**
AGC032
2019/03/23/ 未完成
2019/03/25/ 解説AC
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
    vector<int> b(N), res;
    rep(i, N) cin >> b[i], --b[i];

    

    rep(i, N){
        int p = -1;
        for(int j = (int)b.size()-1; j >= 0; j--){
            if(b[j] == j){
                p = j;
                break;
            }
        }
        if(p == -1){
            cout << -1 << endl;
            return 0;
        }

        res.push_back(p+1);
        b.erase(b.begin() + p);//bからp番目の要素を取り除く
    }

    reverse(res.begin(), res.end());
    for(auto v : res) cout << v << endl;

    return 0;
}