/**
ARC006
2018/12/31/ 自力AC
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
    int E[10] = {0}, B, L[6];
    rep(i, 6){
        int x;
        cin >> x;
        E[x]++;
    }
    cin >> B;
    int num = 0;
    rep(i, 6){
        int l;
        cin >> l;

        if(E[l]) num++;
        if(l == B) E[B]++;
    }

    if(num == 6) cout << 1 << endl;
    else if(num == 5 && E[B] == 1) cout << 2 << endl;
    else if(num == 5) cout << 3 << endl;
    else if(num == 4) cout << 4 << endl;
    else if(num == 3) cout << 5 << endl;
    else cout << 0 << endl;

    return 0;
}