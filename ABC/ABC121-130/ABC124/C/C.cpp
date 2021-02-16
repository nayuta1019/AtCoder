/**
ABC124
2019/04/13/ 初見AC
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

    string s;
    cin >> s;

    int res1 = 0, res2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(i%2 == 0){
            if(s[i] == '1'){
                res1++;
            }
        }else{
            if(s[i] == '0'){
                res1++;
            }
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(i%2 == 0){
            if(s[i] == '0'){
                res2++;
            }
        }else{
            if(s[i] == '1'){
                res2++;
            }
        }
    }

    cout << min(res1, res2) << endl;

    return 0;
}