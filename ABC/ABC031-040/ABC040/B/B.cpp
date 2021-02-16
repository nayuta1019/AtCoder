/**
ABC040
2019/01/02/ 自力AC
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
    int n;
    cin >> n;

    int res = 1e9;
    for(int i = 1; i*i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i*j <= n && n-i*j+abs(i-j) < res){
                res = n-i*j+abs(i-j);
            }
        }
    }

    cout << res << endl;

    return 0;
}

/**
正方形を作るか長方形をつくるか
ans = n - m*m 
ans = n - h*w + abs(h-w)
**/