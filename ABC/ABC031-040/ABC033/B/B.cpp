/**
ABC033
2018/12/31/ 自力AC
過半数以上の町が2つ以上になることはない
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
    vector< pair<string, int> > city;
    int total = 0;
    rep(i, N){
        string s;
        int p;
        cin >> s >> p;
        city.push_back(make_pair(s, p));
        total += p;
    }

    bool flag = true;
    rep(i, N){
        if(total/2 < city[i].second){
            cout << city[i].first << endl;
            flag = false;
        }
    }

    if(flag) cout << "atcoder" << endl;

    return 0;
}