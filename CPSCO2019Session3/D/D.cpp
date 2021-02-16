/**
2019/05/07/ 自力AC
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

    int n;
    string s;
    cin >> n >> s;

    rep(i, n){

        if(i == 0){
            if(s[i] != 'R'){
                cout << "No" << endl;
                return 0;
            }
        }
        
        if(i+1 < n){
            if(s[i] == 'G' && s[i+1] == 'G'){
                cout << "No" << endl;
                return 0;
            }
            if(s[i] == 'R' && s[i+1] == 'B'){
                cout << "No" << endl;
                return 0;
            }
        }

        if(i == n-1){
            if(s[i] != 'B'){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}