/**
2018/12/08/ 解説AC
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

int rr[110000], cc[110000];
int cntr[110000], cntc[110000];

int main(){
    int R, C, K, N;
    cin >> R >> C >> K >> N;
    vector< pair<int, int> > v;

    for(int i = 0; i < N; i++){
        int r, c;
        cin >> r >> c;
        r--; c--;
        rr[r]++;
        cc[c]++;
        v.push_back(pair<int, int>(r, c));
    }

    for(int i = 0; i < R; i++){
        cntr[rr[i]]++;
    }

    for(int i = 0; i < C; i++){
        cntc[cc[i]]++;
    }

    ll ans = 0;
    for(int i = 0; i <= K; i++){
        ans += cntr[i] * cntc[K-i];
    }

    for(auto x : v){
        if(rr[x.first] + cc[x.second] == K){
            ans--;
        }else if(rr[x.first] + cc[x.second] == K + 1){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}