/**
ABC009
2018/12/19/ 解説AC
author:null_null

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

int n, k;
string s, t;
int rest[30];
int ss[101][30];

int main(){
    cin >> n >> k >> s;
    
    for(auto i : s) ++rest[i - 'a'];

    for(int i = 0; i < n; i++) ++ss[i][s[i]-'a'];

    for(int i = n-1; 0 <= i; i--){
        for(int j = 0; j < 26; j++){
            ss[i][j] += ss[i+1][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(0 < rest[j]){
                --rest[j];
                int tmp = 0;
                if(s[i] == 'a'+j) ++tmp;
                
                for(int l = 0; l < 26; l++) tmp += min(rest[l], ss[i+1][l]);

                bool f = n - i - tmp <= k;
                if(!f) rest[j]++;
                else{
                    t += 'a' + j;
                    if(s[i] != 'a' + j) --k;
                    break;
                }
            }
        }
    }
    cout << t << endl;

    return 0;
}