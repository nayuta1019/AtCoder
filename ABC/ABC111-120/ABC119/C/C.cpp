/**
ABC119
2019/03/07/ 解説AC
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

    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    rep(i, N) cin >> l[i];

    int minMP = 1e9;
    for(int bit = 0; bit < (1<<(2*N)); bit++){
        int MP = 0, la = 0, lb = 0, lc = 0;
        int cnta = 0, cntb = 0, cntc = 0;
        for(int i = 0; i < N; i++){
            if( ( ( bit>>(i*2) )&3 ) == 0 ){
                la += l[i];
                if(0 < cnta) MP += 10;
                cnta++;
            }
            if( ( ( bit>>(i*2) )&3 ) == 1 ){
                lb += l[i];
                if(0 < cntb) MP += 10;
                cntb++;
            }
            if( ( ( bit>>(i*2) )&3 ) == 2 ){
                lc += l[i];
                if(0 < cntc) MP += 10;
                cntc++;
            }
            if( ( ( bit>>(i*2) )&3 ) == 3 ){
            }

        }
        if(la == 0 || lb == 0 || lc == 0) continue;
        MP += abs(A - la) + abs(B - lb) + abs(C - lc);
        minMP = min(minMP, MP);
    }

    cout << minMP << endl;

    return 0;
}