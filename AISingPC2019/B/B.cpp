/**
AISingPC2019
2019/01/12/ 自力AC
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
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    int l=0, m=0, u=0;
    rep(i, N){
        if(P[i] <= A) l++;
        if(A+1 <= P[i] && P[i] <= B) m++;
        if(B+1 <= P[i]) u++;
    }

    cout << min({l,m,u}) << endl;

    return 0;
}