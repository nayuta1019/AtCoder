/**
ABC114
2018/12/11/ 解説AC
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

int n, p = 0;
int dp[120][100];

//素数かどうか判定
bool is_prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    dp[0][1] = 1;

    for(int i = 2; i <= n; i++){
        if(is_prime(i) == false) continue; //素数でないなら
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            int a = j;
            while(a % i == 0){
                cnt++;
                a /= i;
            }
        }
        for(int j = 0; j <= cnt; j++){
            for(int k = 1; k * (j + 1) <= 75; k++){
                dp[i][k*(j+1)] += dp[p][k];
            }
        }
        p = i;
    }

    cout << dp[p][75] << endl;

    return 0;
}