/**
ABC080
2019/02/11/ 解説AC
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

int N, C;
int s[100000], t[100000], c[100000];
int sm[200002];
int tt[200002];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    scanf("%d%d", &N, &C);
    for(int i = 0; i < N; i++) scanf("%d%d%d", &s[i], &t[i], &c[i]);

    for(int i = 1; i <= C; i++){
        for(int j = 0; j < 200002; j++) tt[j] = 0;
        //累積和
        for(int j = 0; j < N; j++){
            if(c[j] == i){
                tt[s[j]*2-1]++;
                tt[t[j]*2]--;
            }
        }
        for(int j = 1; j < 200002; j++) tt[j] += tt[j-1];
        //録画機がどの区間で使われているか
        for(int j = 0; j < 200002; j++){
            if(tt[j] > 0){
                sm[j]++;
            }
        }
    }
    int mx = 0;
    for(int j = 0; j < 200002; j++) if(mx < sm[j]) mx = sm[j];
    printf("%d\n", mx);

    return 0;
}