/**
2018/12/01/ 自力AC
添え字をしっかり確認！
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
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    rep(i, N) cin >> x[i] >> y[i] >> h[i];
    
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            ll H = -1;
            bool flag = true;
            for(int k = 0; k < N; k++){
                if(h[k] != 0){
                    if(H != -1 && H != h[k] + abs(x[k] - i) + abs(y[k] - j)){
                        flag = false;
                    }else{
                        H = h[k] + abs(x[k] - i) + abs(y[k] - j);
                    }
                }
            }

            if(flag == false) continue;

            for(int k = 0; k < N; k++){
                if(h[k] == 0){
                    if(0 < H - abs(x[k] - i) - abs(y[k] - j) ){
                        flag = false;
                    }
                }
            }

            if(flag){
                printf("%d %d %lld\n", i, j, H);
                return 0;
            }
        }
    }

    return 0;
}